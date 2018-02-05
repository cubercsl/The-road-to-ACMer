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

int dp[1005][10][10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s, t;
    while (cin >> s >> t)
    {
        int n = s.length();
        clr(dp, 0x3f);
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                {
                    int c = (20 + t[i] - s[i] - j) % 10;
                    for (int a = 0; a <= c; a++)
                        for (int b = 0; b <= a; b++)
                            dp[i + 1][(k + a) % 10][b] = min(dp[i + 1][(k + a) % 10][b], dp[i][j][k] + c);
                    c = (10 - c) % 10;
                    for (int a = 0; a <= c; a++)
                        for (int b = 0; b <= a; b++)

                            dp[i + 1][(k - a + 10) % 10][(10 - b) % 10] = min(dp[i + 1][(k - a + 10) % 10][(10 - b) % 10], dp[i][j][k] + c);
                }
        cout << dp[n][0][0] << endl;
    }
    return 0;
}
