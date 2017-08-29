// To the Max, POJ1050

/*Sample Input
4
 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2
*/

#include <cstdio>
#include <vector>
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

const int maxn = 105;
int pre[maxn][maxn];
int dp[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        int tmp;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &tmp);
                pre[i][j] = pre[i][j - 1] + tmp;
            }
        int ans = -INF;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                int sum = 0;
                for (int k = 1; k <= n; k++)
                {
                    sum = max(sum, 0);
                    sum += pre[k][j] - pre[k][i - 1];
                    ans = max(ans, sum);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
