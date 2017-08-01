// Stockbroker Grapevine

/*Sample Input
3
2 2 4 3 5
2 1 2 3 6
2 1 2 2 2
5
3 4 4 2 8 5 3
1 5 8
4 1 6 4 10 2 7 5 2
0
2 2 5 1 5
0
*/

#include <iostream>
#include <cstring>
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
int dp[maxn][maxn];
int t;

void floyd()
{
    for (int k = 1; k <= t; k++)
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= t; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

int main()
{
    fastin
    while (cin >> t, t)
    {
        clr(dp, 0x3f);
        for (int i = 1; i <= t; i++)
        {
            int n;
            cin >> n;
            dp[i][i] = 0;
            while (n--)
            {
                int a, val;
                cin >> a >> val;
                dp[i][a] = val;
            }
        }
        floyd();
        int ans = INF, flag;
        for (int i = 1; i <= t; i++)
        {
            int m = 0;
            for (int j = 1; j <= t; j++)
                m = max(dp[i][j], m);
            if (m < ans)
            {
                ans = m;
                flag = i;
            }
        }
        if (ans == INF) cout << "disjoint" << endl;
        else
            cout << flag << " " << ans << endl;
    }
    return 0;
}
