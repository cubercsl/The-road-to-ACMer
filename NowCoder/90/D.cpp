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

const int N = 1500;
int dp[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        int n = s.length();
        for (auto& t : s)
            if (t >= 'a' && t <= 'z') (t -= 'a') += 'A';
        clr(dp, 0);
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int i = 1; i < n; ++i)
        {
            int tmp = 0;
            for (int j = 0; j + i < n; j++)
            {
                if (s[j] == s[j + i])
                    tmp = dp[j + 1][j + i - 1] + 2;
                else
                    tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);
                dp[j][j + i] = tmp;
            }
        }
        cout << n - dp[0][n - 1] << endl;
    }
    return 0;
}
