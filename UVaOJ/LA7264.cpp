#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f)
        : from(u), to(v), cap(c), flow(f) {}
};

const int maxn = 1 << 10;
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
            //从上次考虑的弧
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
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} gao;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, s;
        scanf("%d%d%d", &n, &m, &s);
        gao.init(n * 2 + 2);
        int S = 0, T = n * 2 + 1;
        for (int i = 0, a, b, c; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            gao.AddEdge(n + a, b, c);
        }
        for (int i = 1, a; i <= n; i++)
        {
            scanf("%d", &a);
            gao.AddEdge(S, i, a);
        }
        for (int i = 1, a; i <= n; i++)
        {
            scanf("%d", &a);
            gao.AddEdge(i, i + n, a);
        }
        gao.AddEdge(s, T, INF);
        printf("%d\n", gao.Maxflow(S, T));
    }
}