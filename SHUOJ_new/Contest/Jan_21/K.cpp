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

int dp[10005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        clr(dp, 0);
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        int c = accumulate(v.begin(), v.end(), 0);
        for (auto& t : v)
            for (int i = c / 2; i >= t; i--)
                dp[i] = max(dp[i - t] + t, dp[i]);
        cout << dp[c / 2] << " " << c - dp[c / 2] << endl;
    }
    return 0;
}
