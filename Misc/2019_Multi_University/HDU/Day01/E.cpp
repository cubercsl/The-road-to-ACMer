#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct HeapNode
{
    ll d;
    int u;
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};
const int maxn = 10005;
struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    ll d[maxn];
    int p[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++) d[i] = 1e18;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        q.push({0, s});
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = id;
                    q.push({d[e.to], e.to});
                }
            }
        }
    }
} s1, s2;
namespace Flow
{

struct Edge
{
    int from, to;
    ll cap, flow;
    Edge(int u, int v, int c, int f)
        : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    ll d[maxn];
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
    int DFS(int x, ll a)
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
    ll Maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        ll flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, 1e18);
        }
        return flow;
    }
} gao;
} // namespace Flow

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Edge> edges;
        s1.init(n);
        s2.init(n);
        for (int i = 0, u, v, w; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            s1.AddEdge(u, v, w);
            s2.AddEdge(v, u, w);
            edges.emplace_back(u, v, w);
        }
        s1.dijkstra(0);
        s2.dijkstra(n - 1);
        // for (int i = 0; i < n; i++) cerr << s1.d[i] << ' ';
        // for (int i = 0; i < n; i++) cerr << s2.d[i] << ' ';
        Flow::gao.init(n);
        for (auto& e : edges)
        {
            if (s1.d[e.from] + s2.d[e.to] + e.dist == s1.d[n - 1])
                Flow::gao.AddEdge(e.from, e.to, e.dist);
        }
        printf("%lld\n", Flow::gao.Maxflow(0, n - 1));
    }
}