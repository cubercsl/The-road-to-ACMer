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

const int maxn = 1 << 20;
ll dp[maxn];
const int maxk = 20;
int fa[maxn][maxk];
int rnk[maxn];

vector<pair<int, ll> > G[maxn];

void dfs(int u, int p)
{
    for (auto& e : G[u])
    {
        if (e.first != p)
        {
            dp[e.first] = (dp[u] + e.second) % mod;
            fa[e.first][0] = u;
            rnk[e.first] = rnk[u] + 1;
            for (int k = 1; k < 20; k++) fa[e.first][k] = fa[fa[e.first][k - 1]][k - 1];
            dfs(e.first, u);
        }
    }
}
int lca(int u, int v)
{
    if (rnk[u] < rnk[v]) swap(u, v);
    for (int k = 19; ~k; k--)
        if (rnk[v] <= rnk[fa[u][k]]) u = fa[u][k];
    if (u == v) return u;
    for (int k = 19; ~k; k--)
        if (fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
    return fa[u][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i < n; i++)
    {
        static int u, v;
        static ll w, l;
        scanf("%d%d%lld%lld", &u, &v, &w, &l);
        if (l & 1)
            G[u].push_back({v, mod - w}), G[v].push_back({u, mod - w}), sum += 1LL * (l + 1) * w % mod;
        else
            G[u].push_back({v, w}), G[v].push_back({u, w}), sum += 1LL * l * w % mod;
        sum %= mod;
    }
    dp[1] = 0;
    for (int k = 0; k < 20; k++) fa[1][k] = 1;
    rnk[1] = 0;
    dfs(1, 0);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        static int s, t;
        scanf("%d%d", &s, &t);
        int up = lca(s, t);
        ll ans = (sum + dp[s] + dp[t] - dp[up] * 2 + mod + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
