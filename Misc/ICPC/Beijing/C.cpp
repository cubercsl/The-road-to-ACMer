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

const int maxn = 305;
int a[maxn][maxn];
int b[maxn], mm[maxn];
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, P;
    dp[0] = -INF;
    while (~scanf("%d%d%d", &n, &m, &P))
    {
        int tot = 0, minv = INF;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                tot += a[i][j];
                minv = min(minv, a[i][j]);
            }
        int ans = -INF;
        for (int i = 1; i <= n; i++)
        {
            clr(b, 0);
            clr(mm, 0x3f);
            for (int j = i; j <= n; j++)
            {
                int sum = 0;
                for (int k = 1; k <= m; k++)
                {
                    b[k] += a[j][k];
                    mm[k] = min(mm[k], a[j][k]);
                    sum = max(sum, 0);
                    sum += b[k];
                    dp[k] = max(dp[k - 1] + b[k], sum - mm[k] + P);
                    if (i == 1 && j == n && k == m && tot == sum)
                        ans = max(ans, sum - minv + P);
                    else
                        ans = max(ans, max(dp[k], sum));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
