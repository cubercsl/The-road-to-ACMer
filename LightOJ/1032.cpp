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

const int maxn = 35;
ll dp[maxn][maxn][2];
bool dight[maxn];

ll dfs(int pos, int sum, bool pre, bool flag)
{
    if (pos == -1) return sum;
    if (!flag && dp[pos][sum][pre] != -1) return dp[pos][sum][pre];
    ll ans = 0;
    int u = flag ? dight[pos] : 1;
    for (int i = 0; i <= u; i++)
        ans += dfs(pos - 1, sum + (pre & i), i, flag && i == u);
    if (!flag) dp[pos][sum][pre] = ans;
    return ans;
}

ll solve(int n)
{
    int len = 0;
    while (n)
    {
        dight[len++] = n & 1;
        n >>= 1;
    }
    return dfs(len - 1, 0, 0, 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(dp, -1);
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %lld\n", ++kase, solve(n));
    }
    return 0;
}
