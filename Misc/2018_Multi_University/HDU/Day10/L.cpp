#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

const int maxn = 1 << 9;

const int INF = 0x3f3f3f3f;

struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn]; //是否在队列中
    int d[maxn];   //bellmanford
    int p[maxn];   //上一条弧
    int a[maxn];   //可改进量
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.emplace_back(from, to, cap, 0, cost);
        edges.emplace_back(to, from, 0, 0, -cost);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BellmanFord(int s, int t, int& flow, ll& cost)
    {
        for (int i = 0; i < n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] > 0) return false; // 当没有可增广的路时退出
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    int MincostMaxflow(int s, int t, ll& cost)
    {
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost))
            ;
        return flow;
    }
} gao;

struct Node
{
    int s, t, w, op;
} v[205];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k, w;
        scanf("%d%d%d%d", &n, &m, &k, &w);
        gao.init(m * 2 + 4);
        int s = m * 2, t = m * 2 + 1;
        int ss = s + 2;
        gao.AddEdge(s, ss, k, 0);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &v[i].s, &v[i].t, &v[i].w, &v[i].op);
            gao.AddEdge(ss, i, INF, 0);
            gao.AddEdge(i, m + i, 1, -v[i].w);
            gao.AddEdge(m + i, t, INF, 0);
            for (int j = 0; j < i; j++)
            {
                if (v[j].t <= v[i].s)
                {
                    int cost = 0;
                    if (v[i].op == v[j].op) cost = w;
                    gao.AddEdge(m + j, i, INF, cost);
                }
                if (v[i].t <= v[j].s)
                {
                    int cost = 0;
                    if (v[i].op == v[j].op) cost = w;
                    gao.AddEdge(m + i, j, INF, cost);
                }
            }
        }
        ll cost;
        gao.MincostMaxflow(s, t, cost);
        printf("%lld\n", -cost);
    }
}