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

const int maxn = 1e6 + 5;
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
        if (d[t] == INF) return false; // 当没有可增广的路时退出
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
        while (BellmanFord(s, t, flow, cost)) ;
        return flow;
    }
} ans;

const int N = 105;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    char s[N];
    int b[N];
    int cnt[26];
    int n;
    while (~scanf("%d", &n))
    {
        scanf("%s", s + 1);
        clr(cnt, 0);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", b + i);
            cnt[s[i] - 'a']++;
        }
        int S = 0;
        int LV_1 = n * 26, LV_2 = LV_1 + n / 2 * 26, LV_3 = LV_2 + n / 2;
        int T = LV_3 + 27;
        ans.init(T + 1);
        for (int i = 0; i < 26; i++)
        {
            ans.AddEdge(S, LV_3 + i + 1, cnt[i], 0);
            for (int j = 1; j <= n; j++)
                ans.AddEdge(LV_3 + i + 1, i * n + j, 1, s[j] - 'a' == i ? -b[j] : 0);
        }
        for (int i = 0; i < 26; i++)
            for (int j = 1; j <= n / 2; j++)
            {
                int x = i * n + j, y = i * n + n + 1 - j;
                int o = LV_1 + (n / 2) * i + j, oo = LV_2 + j;
                ans.AddEdge(x, o, 1, 0);
                ans.AddEdge(y, o, 1, 0);
                ans.AddEdge(o, oo, 1, 0);
            }
        for (int j = 1; j <= n / 2; j++)
            ans.AddEdge(LV_2 + j, T, 2, 0);
        ll cost;
        ans.MincostMaxflow(S, T, cost);
        printf("%lld\n", -cost);
    }
    return 0;
}
