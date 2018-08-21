#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 81;
ll dp[N][N][N * N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, mod;
        scanf("%d%d%d", &n, &m, &mod);
        memset(dp, 0, sizeof(dp));
        dp[1][1][1] = n * m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= i * j; k++)
                {
                    if (i == 1 && j == 1) break;
                    dp[i][j][k] += dp[i][j][k - 1] * (i * j - k + 1) % mod;
                    dp[i][j][k] += dp[i - 1][j][k - 1] * (n - i + 1) * j % mod;
                    dp[i][j][k] += dp[i][j - 1][k - 1] * (m - j + 1) * i % mod;
                    dp[i][j][k] %= mod;
                }
        printf("%lld\n", dp[n][m][n * m]);
    }
}
