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
const ll INF = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
ll a[maxn];
ll s[4];
ll dp[maxn];
int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    fastin int n;
    while (cin >> n >> s[0] >> s[1] >> s[2])
    {
        clr(dp, 0);
        dp[0] = -3 * INF;
        int num;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i < 3; i++)
            for (int j = 1; j <= n; j++) {
                dp[j] = max(dp[j - 1], dp[j] + a[j] * s[i]);
                // cout << dp[j] << endl;
            }
        cout << dp[n] << endl;
    }
    return 0;
}
