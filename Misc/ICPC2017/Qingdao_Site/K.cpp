#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 20005;
struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.pb(Edge(from, to, cap, 0, cost));
        edges.pb(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    bool BellmanFord(int s, int t, int& flow, ll& cost)
    {
        for (int i = 0; i < n; i++) d[i] = INF;
        clr(inq, 0);
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
        if (d[t] == INF) return false;
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
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        map<string, int> M;
        M["Xian"] = 1, M["Qingdao"] = 2, M["Hongqiao"] = 3, M["Pudong"] = 4;
        int sz = 5;
        int s = 0, t = 1;
        int m;
        cin >> m;
        ans.init(maxn);
        ans.AddEdge(s, 2, 1, 0);
        ans.AddEdge(s, 4, 2, 0);
        ans.AddEdge(7, t, 2, 0);
        ans.AddEdge(9, t, 1, 0);
        ans.AddEdge(2, 3, 1, 0);
        ans.AddEdge(4, 5, 2, 0);
        ans.AddEdge(6, 7, 2, 0);
        ans.AddEdge(8, 9, 1, 0);
        while (m--)
        {
            static string u, v;
            static int cost;
            cin >> u >> v >> cost;
            if (!M[u]) M[u] = sz, ans.AddEdge(sz << 1, sz << 1 | 1, 1, 0), sz++;
            if (!M[v]) M[v] = sz, ans.AddEdge(sz << 1, sz << 1 | 1, 1, 0), sz++;
            static int a, b;
            a = M[u], b = M[v];
            ans.AddEdge(a << 1 | 1, b << 1, INF, cost);
            ans.AddEdge(b << 1 | 1, a << 1, INF, cost);
        }
        ll cost;
        int flow = ans.MincostMaxflow(s, t, cost);
        if (flow == 3)
            cout << cost << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
