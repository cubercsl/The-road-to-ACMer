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

const int N = 1e6 + 5;
vector<PII> G[N];

int pre[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
stack<int> S;
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto e : G[u])
    {
        int v = e.X;
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

ll sum[N];

ll f(int x)
{
    int l = 0, r = x;
    ll t;
    while (l <= r)
    {
        ll m = l + r >> 1;
        if (x - m * (m + 1) / 2 >= 0)
            t = m, l = m + 1;
        else
            r = m - 1;
    }
    return x * (t + 1) - sum[t];
}

ll c[N];
vector<PII> g[N];
ll dp[N];

ll DFS(int u)
{
    if (~dp[u]) return dp[u];
    ll& ret = dp[u];
    ret = 0;
    for (auto e : g[u])
    {
        int v = e.X, w = e.Y;
        ret = max(ret, DFS(v) + w);
    }
    ret += c[u];
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + i * (ll)(i + 1) / 2;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++) G[i].clear(), g[i].clear();
        clr(c, 0), clr(dp, -1);
        while (m--)
        {
            static int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            --x, --y;
            G[x].pb(mp(y, w));
        }
        find_scc(n);
        for (int u = 0; u < n; u++)
            for (auto e : G[u])
            {
                int v = e.X, w = e.Y;
                int uu = sccno[u], vv = sccno[v];
                if (uu == vv)
                    c[uu] += f(w);
                else
                    g[uu].pb(mp(vv, w));
            }
        int s;
        scanf("%d", &s);
        s = sccno[--s];
        printf("%lld\n", DFS(s));
    }
    return 0;
}