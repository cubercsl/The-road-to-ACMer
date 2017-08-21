// Minimum cost, POJ2516

/*Sample Input
1 3 3
1 1 1
0 1 1
1 2 2
1 0 1
1 2 3
1 1 1
2 1 1

1 1 1
3
2
20

0 0 0
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 105;
const int maxm = 55;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];      //是否在队列中
    int d[maxn];        //bellmanford
    int p[maxn];        //上一条弧
    int a[maxn];        //可改进量
    void init(int n)
    {
        this-> n = n;
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
        if (d[t] == INF) return false;   // 当没有可增广的路时退出
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
        while (BellmanFord(s, t, flow, cost));
        return flow;
    }
} ans;

int need[maxm], supply[maxm], to[maxm][maxm], from[maxm][maxm], cost[maxm][maxm][maxm];

bool ok(int k)
{
    for (int i = 0; i < k; i++)
        if (need[i] > supply[i]) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k), n + m + k)
    {
        clr(supply, 0);
        clr(need, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &to[i][j]);
                need[j] += to[i][j];
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &from[i][j]);
                supply[j] += from[i][j];
            }
        for (int p = 0; p < k; p++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    scanf("%d", &cost[p][i][j]);
        if (!ok(k))  //供不应求
        {
            puts("-1");
            continue;
        }
        int s = n + m, t = s + 1;
        ll res = 0;
        for (int p = 0; p < k; p++)
        {
            ans.init(t + 1);
            for (int i = 0; i < m; i++) ans.AddEdge(s, i, from[i][p], 0);
            for (int i = 0; i < n; i++)
            {
                ans.AddEdge(m + i, t, to[i][p], 0);
                for (int j = 0; j < m; j++)
                    ans.AddEdge(j, m + i, INF, cost[p][i][j]);
            }
            ll cost;
            ans.MincostMaxflow(s, t, cost);
            res += cost;
        }
        printf("%lld\n", res);
    }
    return 0;
}
