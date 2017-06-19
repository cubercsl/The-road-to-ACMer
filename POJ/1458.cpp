// Common Subsequence

/*Sample input
abcfbc         abfcab
programming    contest 
abcd           mnp
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 2;
char X[maxn], Y[maxn];
int dp[maxn][maxn];

int main()
{
    while (cin >> X >> Y)
    {
        memset(dp, 0, sizeof(dp));
        int n = strlen(X), m = strlen(Y);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        cout << dp[n][m] << endl;
    }
    return 0;
}
