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

const int N = 1 << 11;
int s1[N], s2[N];
ll dp[N][N];
ll sa[N], sb[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", s1 + i);
        for (int i = 1; i <= m; i++) scanf("%d", s2 + i);
        sort(s1 + 1, s1 + n + 1);
        sort(s2 + 1, s2 + m + 1);
        dp[0][0] = 0;
        sa[0] = sb[0] = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            sa[i] = sa[i - 1] + s1[i];
            dp[i][0] = dp[i - 1][0] + (c - sa[i]) * a;
            if (sa[i] <= c) ans = max(ans, dp[i][0]);
        }
        for (int i = 1; i <= m; i++)
        {
            sb[i] = sb[i - 1] + s2[i];
            dp[0][i] = dp[0][i - 1] + (c - sb[i]) * b;
            if (sb[i] <= c) ans = max(ans, dp[0][i]);
        }
        for (int i = 1; i <= n && sa[i] <= c; i++)
        {
            for (int j = 1; j <= m && sa[i] + sb[j] <= c; j++)
            {
                ll cur = c - sa[i] - sb[j];
                dp[i][j] = max(dp[i - 1][j] + cur * a, dp[i][j - 1] + cur * b);
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
