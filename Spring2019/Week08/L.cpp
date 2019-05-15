#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f)
        : from(u), to(v), cap(c), flow(f) {}
};

const int maxn = 1 << 18;
const int INF = 0x3f3f3f3f;
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
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
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
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
    int Maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }

    void bfs(int s, bool vis[], bool d)
    {
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (!vis[e.to] && (e.cap - e.flow) > 0 == d) q.push(e.to), vis[e.to] = true;
            }
        }
    }
} gao;

bool Left[maxn], Right[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    gao.init(n * 2 + 2);
    int s = 0, t = n * 2 + 1;
    for (int i = 1; i <= n; i++) gao.AddEdge(s, i, 1), gao.AddEdge(n + i, t, 1);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        gao.AddEdge(u, n + v, 1);
    }
    int ans = n - gao.Maxflow(s, t) - 1;
    printf("%d\n", ans);
    if (ans == 0) return 0;
    gao.bfs(s, Left, true);
    gao.bfs(t, Right, false);
    for (int i = 1; i <= n; i++)
        if (Left[i] || Right[i + n]) printf("%d ", i);
    puts("");
}
