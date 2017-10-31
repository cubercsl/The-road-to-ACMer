// Coding Contest, HDU5988

/*Sample Input
1
4 4
2 0
0 3
3 0
0 3
1 2 5 0.5
3 2 5 0.5
1 4 5 0.5
3 4 5 0.5
*/

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

struct Edge
{
    int from, to, cap, flow;
    double cost;
    Edge(int u, int v, int c, int f, double w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

const int maxn = 105;
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];  //是否在队列中
    double d[maxn]; //bellmanford
    int p[maxn];    //上一条弧
    int a[maxn];    //可改进量
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, double cost)
    {
        edges.pb(Edge(from, to, cap, 0, cost));
        edges.pb(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    bool BellmanFord(int s, int t, int& flow, double& cost)
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
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost + eps)
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
        if (d[t] == INF) return false; // 当没有可增广的路时退出
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    int MincostMaxflow(int s, int t, double& cost)
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
    scanf("%d", &T);
    while (T--)
    {
        static int n, m;
        scanf("%d%d", &n, &m);
        int s = 0, t = n + 1;
        ans.init(t + 1);
        for (int i = 1; i <= n; i++)
        {
            static int a, b, c;
            scanf("%d%d", &a, &b);
            c = a - b;
            if (c > 0)
                ans.AddEdge(s, i, c, 0);
            else if (c < 0)
                ans.AddEdge(i, t, -c, 0);
        }
        while (m--)
        {
            static int u, v, c;
            static double p;
            scanf("%d%d%d%lf", &u, &v, &c, &p);
            if (c == 0) continue;
            if (c > 1) ans.AddEdge(u, v, c - 1, -log(1 - p));
            ans.AddEdge(u, v, 1, 0);
        }
        double p;
        ans.MincostMaxflow(s, t, p);
        p = 1 - exp(-p);
        printf("%.2f\n", p);
    }
    return 0;
}
