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

const int N = 1 << 10;
vector<int> G[N];
int v[N];
int dp[N][N];
int tmp[N];
int ans[N];
ll inv2 = mod - mod / 2;

void fwt(int* f, const int& m, bool rev = false)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = (l + r) % mod;
                f[j] = (l - r + mod) % mod;
            }
    if (rev)
    {
        ll inv = 1;
        for (int i = 0; i < n; i++) (inv *= inv2) %= mod;
        for (int i = 0; i < m; i++) f[i] = 1LL * f[i] * inv % mod;
    }
}

inline void gao(int* a, int* b, const int& m)
{
    fwt(a, m), fwt(b, m);
    for (int i = 0; i < m; i++) a[i] = 1LL * a[i] * b[i] % mod;
    fwt(a, m, 1);
}

void dfs(int u, int fa, const int& m)
{
    dp[u][v[u]] = 1;
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u, m);
        memcpy(tmp, dp[u], sizeof(tmp));
        gao(dp[u], dp[v], m);
        for (int i = 0; i < m; i++) (dp[u][i] += tmp[i]) %= mod;
    }
    for (int i = 0; i < m; i++) (ans[i] += dp[u][i]) %= mod;
}

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
        clr(dp, 0);
        clr(ans, 0);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", v + i), G[i].clear();
        for (int i = 1; i < n; i++)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u].pb(v), G[v].pb(u);
        }
        dfs(0, -1, m);
        for (int i = 0; i < m; i++) printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');
    }
    return 0;
}