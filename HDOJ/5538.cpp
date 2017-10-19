// House Building, HDU5538

/*Sample Input
2
3 3
1 0 0
3 1 2
1 1 0
3 3
1 0 1
0 0 0
1 0 1
*/
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

int a[55][55];

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
        int n, m;
        clr(a, 0);
        scanf("%d%d", &n, &m);
        int sum = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                sum += (a[i][j] != 0);
            }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                sum += max(0, a[i][j] - a[i][j - 1]);
            for (int j = m; j > 0; j--)
                sum += max(0, a[i][j] - a[i][j + 1]);
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
                sum += max(0, a[j][i] - a[j - 1][i]);
            for (int j = n; j > 0; j--)
                sum += max(0, a[j][i] - a[j + 1][i]);
        }
        printf("%d\n", sum);
    }
    return 0;
}
