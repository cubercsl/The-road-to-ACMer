// six sheep
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 20005;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w):from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn]; //是否在队列中
    int d[maxn]; //bellmanford 到源点距离
    int p[maxn]; //上一条弧
    int a[maxn]; //可改进量

    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
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
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false; // 当没有可增广的路时退出
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
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
};

MCMF ans;
map<string, int> M;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int id = 4;
        M.clear();
        M["Dalian"] = 1;
        M["Shanghai"] = 2;
        M["Xian"] = 3;
        ans.init(maxn);

        for (int i = 0; i < n; i++)
        {
            string u, v;
            int w;
            cin >> u >> v >> w;
            if (M[u] == 0)
                M[u] = id++;
            if (M[v] == 0)
                M[v] = id++;
            ans.AddEdge(M[u] * 2 + 1, M[v] * 2, 1, w);
            ans.AddEdge(M[v] * 2 + 1, M[u] * 2, 1, w);
        }
        for (int i = 1; i < id; i++)
            ans.AddEdge(i * 2, i * 2 + 1, 1, 0);
        ans.AddEdge(0, 5, 2, 0);
        ans.AddEdge(3, 1, 1, 0);
        ans.AddEdge(7, 1, 1, 0);

        ll cost;
        int flow = ans.MincostMaxflow(0, 1, cost);
        if (flow != 2)
            cout << -1 << '\n';
        else
            cout << cost << '\n';
    }
}
