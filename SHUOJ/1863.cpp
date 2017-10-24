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

const int maxn = 105;
int dp[maxn], p[maxn], h[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        clr(dp, 0x3f);
        for (int i = 0; i < n; i++)
            cin >> p[i] >> h[i];
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int r = p[i] + 1;
            for (int j = i; j < n && p[j] < r; j++)
                dp[j + 1] = min(dp[j + 1], dp[i] + 1), r = max(r, p[j] + h[j]);
            int l = p[i];
            for (int j = i; j < n; j++)
                if (p[j] - h[j] < l)
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1), l = p[j];
        }
        cout << dp[n] << endl;
    }
    return 0;
}
