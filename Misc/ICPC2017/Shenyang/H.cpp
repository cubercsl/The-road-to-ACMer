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
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int val[maxn];
int dp[maxn][2];
vector<PII> G[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++)
        G[i].clear();
}

void addedge(int u, int v, int w)
{
    G[u].pb(mp(v, w));
    G[v].pb(mp(u, w));
}

void dfs(int u, int p)
{
    dp[u][0] = val[u];
    dp[u][1] = val[u];
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].X;
        int w = G[u][i].Y;
        if (p == v) continue;
        dfs(v, u);
        dp[u][0] = min(dp[u][0], dp[v][0] + w);
        dp[u][1] = max(dp[u][1], dp[v][1] - w);
    }
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
        int n;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= n; i++)
            scanf("%d", val + i);
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        dfs(1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dp[i][1] - dp[i][0]);
        printf("%d\n", ans);
    }
    return 0;
}
