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
int a[25][1005];
int dp[25][1005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    clr(a, 0xc0);
    cin >> T;
    while (T--)
    {
        int n, m;
        clr(dp, 0xc0);
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        dp[1][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                for (int k = 1; k < j; k++)
                    if (j % k == 0)
                        dp[i][j] = max(dp[i][j], dp[i][k]);
                dp[i][j] += a[i][j];
            }
        cout << dp[n][m] << endl;
    }
    return 0;
}