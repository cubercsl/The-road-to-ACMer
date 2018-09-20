#include <bits/stdc++.h>
using namespace std;

const int mod = 119 << 23 | 1;
typedef long long ll;

int dp[1 << 10][1 << 11][1 << 2];

int w[][4] = {0, 1, 1, 1,
              0, 0, 2, 0,
              0, 2, 0, 0,
              1, 1, 1, 0};

int main()
{
    dp[0][1][0] = 1;
    dp[0][1][3] = 1;
    dp[0][2][1] = 1;
    dp[0][2][2] = 1;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                    (dp[i + 1][j + w[x][y]][y] += dp[i][j][x]) %= mod;
    ll ans = 0;
    for (int i = 0; i < 4; i++)
        (ans += dp[n - 1][k][i]) %= mod;
    printf("%lld\n", ans);
}