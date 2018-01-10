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

const int N = 35005;
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
        clr(dp, 0);
        int c, n;
        cin >> c >> n;
        while (n--)
        {
            static int w;
            cin >> w;
            for (int i = c; i >= w; i--)
                dp[i] = max(dp[i], dp[i - w] + w);
        }
        cout << dp[c] << endl;
    }
    return 0;
}
