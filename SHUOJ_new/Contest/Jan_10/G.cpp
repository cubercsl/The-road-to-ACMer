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

const int N = 1080005;
int dp[N];

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
        int n, t;
        cin >> n >> t;
        clr(dp, 0);
        while (n--)
        {
            static int w1, t1, w2, t2;
            cin >> w1 >> t1 >> w2 >> t2;
            for (int i = t; i > 0; i--)
            {
                if (i >= t1 && i >= t2)
                    dp[i] = max(dp[i], max(dp[i - t1] + w1, dp[i - t2] + w2));
                else if (i >= t1)
                    dp[i] = max(dp[i], dp[i - t1] + w1);
                else if (i >= t2)
                    dp[i] = max(dp[i], dp[i - t2] + w2);
            }
        }
        cout << dp[t] << endl;
    }
    return 0;
}
