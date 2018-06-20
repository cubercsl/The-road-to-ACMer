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

const int N = 1 << 20;

int dp[N];
int premax[N];
int s[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &m, &n))
    {
        clr(dp, 0);
        clr(premax, 0);
        for (int i = 1; i <= n; i++) scanf("%d", s + i);
        int ans;
        for (int i = 1; i <= m; i++)
        {
            ans = -INF;
            for (int j = i; j <= n; j++)
            {
                dp[j] = max(dp[j - 1] + s[j], premax[j - 1] + s[j]);
                premax[j - 1] = ans;
                ans = max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
