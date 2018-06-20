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
vector<int> G[N];
int dp[N][2];
int val[N], deg[N];

void dfs(int u)
{
    dp[u][0] = 0, dp[u][1] = val[u];
    for (auto& v : G[u])
    {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", val + i);
        static int u, v;
        while (~scanf("%d%d", &v, &u), u + v) G[u].push_back(v), ++deg[v];
        int rt = 0;
        for (int i = 1; i <= n && !rt; i++)
            if (!deg[i]) rt = i;
        assert(rt);
        dfs(rt);
        printf("%d\n", max(dp[rt][0], dp[rt][1]));
    }
    return 0;
}
