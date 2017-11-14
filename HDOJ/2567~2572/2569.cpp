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
    int t, n;
    cin >> t;
    ll dp[45];
    dp[1] = 3, dp[2] = 9;
    for (int i = 3; i < 45; i++) dp[i] = 2 * dp[i - 1] + dp[i - 2];
    while (t--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}