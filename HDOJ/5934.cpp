// Bomb, HDU5934

/*Sample Input
1
5
0 0 1 5
1 1 1 6
0 1 1 7
3 0 2 10
5 0 1 4
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

const int maxn = 1005;

vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;
inline void add_edge(int u, int v) { G[u].pb(v); }
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    clr(sccno, 0), clr(pre, 0);
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i);
}
typedef pair<double, double> Point;
inline double dis2(Point a, Point b)
{
    double dx = a.X - b.X, dy = a.Y - b.Y;
    return dx * dx + dy * dy;
}

Point P[maxn];
double r[maxn];
int c[maxn];
int in[maxn], cost[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        init(n);
        clr(cost, 0x3f), clr(in, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%d", &P[i].X, &P[i].Y, &r[i], &c[i]);
            for (int j = 0; j < i; j++)
            {
                double tmp = dis2(P[i], P[j]);
                if (tmp <= r[i] * r[i])
                    add_edge(i, j);
                if (tmp <= r[j] * r[j])
                    add_edge(j, i);
            }
        }
        find_scc(n);
        for (int i = 0; i < n; i++)
            cost[sccno[i]] = min(cost[sccno[i]], c[i]);
        for (int i = 0; i < n; i++)
            for (auto& j : G[i])
                if (sccno[i] != sccno[j])
                    in[sccno[j]]++;
        int ans = 0;
        for (int i = 1; i <= scc_cnt; i++)
            if (!in[i]) ans += cost[i];
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
