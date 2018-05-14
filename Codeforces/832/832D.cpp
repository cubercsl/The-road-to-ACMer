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

const int N = 1 << 17;
vector<int> G[N], sp;
int dep[N], dfn[N];
PII dp[21][N << 1];

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& v : G[u])
    {
        if (v != fa) dfs(v, u);
        sp.push_back(u);
    }
}

void init()
{
    int n = sp.size();
    for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}

int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).Y;
}

int query(int a, int b, int c)
{
    int l1 = lca(a, b), l2 = lca(a, c);
    if (l1 == l2)
    {
        int d = dep[a] - dep[l1] + 1;
        int l3 = lca(b, c);
        return d + dep[l3] - dep[l1];
    }
    return dep[a] - max(dep[l1], dep[l2]) + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2, fa; i <= n; i++)
    {
        scanf("%d", &fa);
        G[fa].push_back(i);
    }
    dfs(1, 0);
    init();
    while (q--)
    {
        static int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        ans = max(ans, query(a, b, c));
        ans = max(ans, query(b, a, c));
        ans = max(ans, query(c, a, b));
        printf("%d\n", ans);
    }
    return 0;
}
