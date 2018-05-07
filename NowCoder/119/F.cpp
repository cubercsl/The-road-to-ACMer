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
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n), c(n);
        for (int i = 0; i < n; i++) cin >> v[i] >> c[i];
        int sum = accumulate(c.begin(), c.end(), 0);
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = sum; j >= c[i]; j--)
                dp[j] = min(dp[j], dp[j - c[i]] + v[i]);
        for (int i = sum; ~i; i--)
            if (dp[i] <= k)
            {
                cout << i << endl;
                break;
            }
    }
    return 0;
}
