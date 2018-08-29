#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20000;
int a[N];
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to;
    double cap, flow;
    Edge(int u, int v, double c, double f) : from(u), to(v), cap(c), flow(f) {}
};
const double eps = 1e-8;
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    bool vis[N];
    double d[N];
    int cur[N];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, double cap)
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
            for (auto& id : G[x])
            {
                Edge& e = edges[id];
                if (!vis[e.to] && e.cap > e.flow + eps)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    double DFS(int x, double a)
    {
        if (x == t || a < eps) return a;
        double flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        {
            Edge& e = edges[G[x][i]];
            if ((d[x] + 1 == d[e.to]) && (f = DFS(e.to, min(a, e.cap - e.flow))) > eps)
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
    double Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        double flow = 0;
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
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        vector<pair<int, int> > edges;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[j] > a[i]) edges.emplace_back(j, i);
        int m = edges.size();
        double l = 0, r = m;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            gao.init(n + m + 2);
            int s = n + m, t = n + m + 1;
            for (int i = 0; i < n; i++) gao.AddEdge(i, t, mid);
            for (int i = 0; i < m; i++)
            {
                gao.AddEdge(n + i, edges[i].first, INF);
                gao.AddEdge(n + i, edges[i].second, INF);
                gao.AddEdge(s, n + i, 1.0);
            }
            double flow = m - gao.Maxflow(s, t);
            if (flow < eps)
                r = mid;
            else
                l = mid;
        }
        printf("Case #%d: %.7f\n", ++kase, l);
    }
    return 0;
}