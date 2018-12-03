#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 119 << 23 | 1;
const int N = 1 << 17;
const int M = 201;
ll dp[N][M][2];
// 0 down
// 1 up

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < M; i++) dp[0][i][0] = 1;
    for (int i = 1, t; i <= n; i++)
    {
        cin >> t;
        for (int j = 1; j < M; j++)
        {
            if (t == j || t == -1)
            {
                (dp[i][j][0] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % mod;
                // printf("dp[%d][%d][0]-> %lld\n", i, j, dp[i][j][0]);
                (dp[i][j][1] += dp[i - 1][M - 1][1] - dp[i - 1][j - 1][1] + dp[i - 1][j][0] - dp[i - 1][j - 1][0] + mod * 2) %= mod;
                // printf("dp[%d][%d][1]-> %lld\n", i, j, dp[i][j][1]);
            }
        }
        for (int j = 1; j < M; j++)
            for (int k = 0; k < 2; k++) (dp[i][j][k] += dp[i][j - 1][k]) %= mod;
    }
    cout << dp[n][M - 1][1] << endl;
}