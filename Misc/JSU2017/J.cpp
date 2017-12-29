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
const int mod = 609929123;
const double eps = 1e-6;

ll dp[2005][5];
int x[2005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int m;
    while (cin >> m)
    {
        clr(dp, 0);
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int i = 1; i <= m; i++)
            cin >> x[i];
        for (int i = 1; i <= m; i++)
        {
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] * x[i] % mod) % mod;
            dp[i][2] = (dp[i - 1][2] + dp[i - 1][1] * x[i] % mod) % mod;
            dp[i][3] = (dp[i - 1][3] + dp[i - 1][2] * x[i] % mod) % mod;
        }
        cout << dp[m][3] << endl;
    }
    return 0;
}
