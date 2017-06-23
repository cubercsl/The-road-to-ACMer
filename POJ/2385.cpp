// Apple Catching, POJ2385

/*Sample Input
7 2
2
1
1
2
2
1
1
*/

#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[32][maxn];
int a[maxn][2];
int t, w, ans = -1;

int solve()
{
    dp[0][0] = a[0][0];
    dp[1][0] = a[0][1];
    for (int i = 0; i <= w; i++)
    {
        for (int j = 1; j < t; j++)
        {
            if (i)
                dp[i][j] = max(dp[i - 1][j - 1] + a[j][!(i & 1)], dp[i][j - 1] + a[j][i & 1]);
            else
                dp[i][j] = dp[i][j - 1] + a[j][i & 1];
        }
        ans = max(ans, dp[i][t - 1]);
    }
    return ans;
}


int main()
{
    cin >> t >> w;
    for (int i = 0; i < t; i++)
    {
        int id;
        cin >> id;
        a[i][id - 1] = 1;
    }
    cout << solve() << endl;
    return 0;
}
