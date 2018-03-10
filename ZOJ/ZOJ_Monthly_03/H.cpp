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

const int N = 2005;
int dp[N][N];

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
        int n, m;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                for (int j = 1; j <= m; j++) dp[i + 1][j] = 1;
                continue;
            }
            for (int j = 1; j <= m; j++)
                for (int k = j; k <= m; k += j)
                    (dp[i + 1][k] += dp[i][j]) %= mod;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) (ans += dp[n][i]) %= mod;
        printf("%d\n", ans);
    }
    return 0;
}
