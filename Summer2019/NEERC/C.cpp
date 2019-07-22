#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 450;
const int mod = 119 << 23 | 1;
int dp[N][M];

int main()
{
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) (dp[i][j] += dp[i - j][j]) %= mod;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i * i <= n; i++)
        {
            int r = n - i * i;
            if (r & 1) continue;
            r >>= 1;
            (ans += dp[r][i]) %= mod;
        }
        printf("%lld\n", ans);
    }
}