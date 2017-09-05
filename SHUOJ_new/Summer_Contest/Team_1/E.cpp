#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

const int maxn = 205;
int a[maxn], b[maxn], dp[maxn][2];
vector<int> G[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void addegde(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (auto& v : G[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m, n + m)
    {
        clr(dp, -1);
        init(n);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        for (int i = 0; i < m; i++)
            scanf("%d", b + i);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = 0; k < m; k++)
                    if (abs(a[i] - a[j]) == b[k])
                        addegde(i, j);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i][0] != -1)
                continue;
            dfs(0, -1);
            ans += max(dp[i][0], dp[i][1]);
        }
        cout << ans << endl;
    }
    return 0;
}
