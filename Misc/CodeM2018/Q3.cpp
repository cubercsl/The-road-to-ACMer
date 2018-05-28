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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    vector<vector<ld> > a(16, vector<ld>(16));
    vector<vector<ld> > dp(5, vector<ld>(16));
    for (auto& t : a)
        for (auto& tt : t) cin >> tt;
    for (int i = 0; i < 16; i++) dp[0][i] = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            ld tmp = 0;
            int t = 1 << i;
            for (int k = 0; k < (1 << i); k++) tmp += dp[i][j ^ (t | k)] * a[j][j ^ (t | k)];
            dp[i + 1][j] = dp[i][j] * tmp;
        }
    }
    for (int i = 0; i < 16; i++) printf("%.10Lf%c", dp[4][i], " \n"[i == 15]);
    return 0;
}