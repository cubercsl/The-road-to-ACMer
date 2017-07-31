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

int dp[104][104][12];
int ma[104][104][12];
int g0[104][104];
int main()
{
    int n, q, c;
    while (scanf("%d%d%d", &n, &q, &c) == 3)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            int x, y, t;
            scanf("%d%d%d", &x, &y, &t);
            dp[x][y][t]++;
        }
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                for (int k = 0; k <= 10; k++)
                    dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
        for (int i = 0; i < q; i++)
        {
            int t, x1, x2, y1, y2;
            scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
            ll ans = 0;
            for (int k = 0; k <= 10; k++)
            {
                ll temp = (dp[x2][y2][k] - dp[x1 - 1][y2][k] - dp[x2][y1 - 1][k] + dp[x1 - 1][y1 - 1][k]) * ((t + k) % (c + 1));
                ans += temp;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
