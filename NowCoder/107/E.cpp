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

const int N = 1 << 20;
int dp[N][3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        clr(dp, 0);
        int n = s.length();
        dp[0][s[0] - '0'] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int k = (j * 2 + s[i] - '0') % 3;
                dp[i][k] = dp[i - 1][j] + ((s[i] - '0') == k);
            }
        }
        ll ans = 0;
        /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%2d%c", dp[i][j], " \n"[j == 2]);
    }*/
    for (int i = 0; i < n; i++) ans += dp[i][0];
        cout << ans << endl;
    }
    return 0;
}