// 免费馅饼, HDU1176

/*Sample Input
6
5 1
4 1
6 1
7 2
7 2
8 3
0
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
ll a[maxn][12];
ll dp[2][12];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, T;
    while (~scanf("%d", &n), n)
    {
        T = 0;
        clr(a, 0);
        clr(dp, 0);
        while (n--)
        {
            int x, t;
            scanf("%d%d", &x, &t);
            a[t][x]++;
            T = max(t, T);
        }

        dp[1][4] = a[1][4];
        dp[1][5] = a[1][5];
        dp[1][6] = a[1][6];

        for (int i = 2; i <= T; i++)
        {
            dp[i & 1][0] = max(dp[i & 1 ^ 1][0], dp[i & 1 ^ 1][1]) + a[i][0];
            for (int j = 1; j <= 10; j++)
                dp[i & 1][j] = max(max(dp[i & 1 ^ 1][j - 1], dp[i & 1 ^ 1][j]), dp[i & 1 ^ 1][j + 1]) + a[i][j];
        }
        ll ans = 0;
        for (int i = 0; i <= 10; i++)
            ans = max(ans, dp[T & 1][i]);
        printf("%lld\n", ans);
    }
    return 0;
}
