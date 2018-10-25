#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int N = 1 << 7;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int from, to, cap, flow;
    Edge() {}
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    bool vis[N];
    int d[N];
    int cur[N];
    void init(int n)
    {
        this->n = n;
        edges.clear();
        for (int i = 0; i < n; i++) G[i].clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        dbg(from, to);
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, 0, 0);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto& id : G[x])
            {
                Edge& e = edges[id];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x, int a)
    {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    int MaxFlow(int s, int t)
    {
        dbg(s, t);
        this->s = s, this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        dbg(flow);
        return flow;
    }
} gao;

struct _Edge
{
    int from, to, cost;
    _Edge() {}
    _Edge(int u, int v, int c) : from(u), to(v), cost(c) {}
    bool operator<(const _Edge& rhs) const
    {
        return cost < rhs.cost;
    }
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<_Edge> edges;
    for (int i = 0, u, v, c; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        edges.emplace_back(u, v, c);
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto& e : edges)
    {
        gao.init(n + 1);
        int s = e.from, t = e.to;
        for (auto& ee : edges)
        {
            if (ee.cost >= e.cost) break;
            gao.AddEdge(ee.from, ee.to, 1);
            gao.AddEdge(ee.to, ee.from, 1);
        }
        ans += gao.MaxFlow(s, t);
        dbg("---");
    }
    printf("%d\n", ans);
}