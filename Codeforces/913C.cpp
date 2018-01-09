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

const int N = 35;
ll c[N];
ll dp[N][2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, L;
    while (cin >> n >> L)
    {
        int last = 0;
        clr(c, 0x3f);
        for (int i = 0; i <= 30; i++)
        {
            if (L >> i & 1)
            {
                last = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
            cin >> c[i];

        ll ans = 1e18;
        for (int i = 30; i >= n; i--)
            for (int j = 0; j < n; j++)
                c[i] = min(c[i], 1LL * c[j] * (1 << (i - j)));
        for (int i = 0; i <= 30; i++)
        {
            for (int j = 0; j < i; j++)
                c[i] = min(c[i], 1LL * c[j] * (1 << (i - j)));
            for (int j = i + 1; j <= 30; j++) c[i] = min(c[i], c[j]);
        }
        clr(dp, 0);
        for (int i = 30; i > last; i--)
        {
            if (L >> i & 1)
            {
                if (~dp[i + 1][0])
                {
                    ll tmp = dp[i + 1][0] + (c[i] << 1);
                    ans = min(tmp, ans);
                    dp[i][1] = tmp - c[i];
                }
                else
                {
                    dp[i][1] = dp[i + 1][1] + (c[i] << 1);
                    ans = min(dp[i][1], ans);
                    dp[i][1] -= c[i];
                }
                dp[i][0] = -1;
            }
            else
            {
                if (~dp[i + 1][0])
                {
                    ans = min(ans, dp[i + 1][0] + c[i]);
                    dp[i][0] = dp[i + 1][0];
                }
                else
                {
                    ans = min(ans, dp[i + 1][1] + c[i]);
                    dp[i][0] = dp[i + 1][1];
                }
                dp[i][1] = -1;
            }
        }
        if (~dp[last + 1][0])
            ans = min(ans, dp[last + 1][0] + c[last]);
        else
            ans = min(ans, dp[last + 1][1] + c[last]);
        cout << ans << endl;
    }
    return 0;
}
