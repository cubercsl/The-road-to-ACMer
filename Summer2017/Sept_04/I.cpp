#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

const int maxn = 305;
int a[maxn][maxn];
int dp[maxn][maxn][9][9];
int n, m;

void init()
{

    for (int i = 0; (1 << i) <= n; i++)
        for (int j = 0; (1 << j) <= m; j++)
        {
            if (i == 0 && j == 0) continue;
            for (int row = 1; row + (1 << i) - 1 <= n; row++)
                for (int col = 1; col + (1 << j) - 1 <= m; col++)
                    //当x或y等于0的时候，就相当于一维的RMQ了
                    if (i == 0)
                        dp[row][col][i][j] =
                            max(dp[row][col][i][j - 1],
                                dp[row][col + (1 << (j - 1))][i][j - 1]);
                    else if (j == 0)
                        dp[row][col][i][j] =
                            max(dp[row][col][i - 1][j],
                                dp[row + (1 << (i - 1))][col][i - 1][j]);
                    else dp[row][col][i][j] =
                            max(dp[row][col][i][j - 1],
                                dp[row][col + (1 << (j - 1))][i][j - 1]);
        }
}
int rmq(int x1, int y1, int x2, int y2)
{
    int kx = 0, ky = 0;
    while (x1 + (1 << (1 + kx)) - 1 <= x2) kx++;
    while (y1 + (1 << (1 + ky)) - 1 <= y2) ky++;
    int m1 = dp[x1][y1][kx][ky];
    int m2 = dp[x2 - (1 << kx) + 1][y1][kx][ky];
    int m3 = dp[x1][y2 - (1 << ky) + 1][kx][ky];
    int m4 = dp[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
    return max(max(m1, m2), max(m3, m4));
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                dp[i][j][0][0] = a[i][j];
            }
        init();
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int ans = rmq(x1, y1, x2, y2);
            printf("%d ", ans);
            puts(ans == a[x1][y1] || ans == a[x2][y1] || ans == a[x1][y2] || ans == a[x2][y2] ? "yes" : "no");
        }
    }
    return 0;
}
