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
    string s, t;
    while (cin >> s >> t)
    {
        int n = s.length(), m = t.length();
        string p;
        cin >> p;
        if (n + m != p.length())
        {
            cout << "No" << endl;
            continue;
        }
        clr(dp, 0);
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
            {
                if (p[i + j] == s[i]) dp[i + 1][j] |= dp[i][j];
                if (p[i + j] == t[j]) dp[i][j + 1] |= dp[i][j];
            }
        if(dp[n][m]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}