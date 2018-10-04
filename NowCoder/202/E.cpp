#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int g[N][N];
int dp[1 << N];
int tmp[N];
int w[1 << N][N];
int ww[1 << N];

int main()
{
    int n;
    scanf("%d", &n);
    int m = 2 * n * (n - 1);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u][v]++;
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (i >> k & 1) w[i][j] += g[j][k];
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < j; k++)
                    if (i >> k & 1)
                        ww[i] += abs(g[j][k] - g[k][j]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int U = (1 << n) - 1;
    for (int T = 0; T < (1 << n); T++)
    {
        int S = U & ~T;
        for (int s = S; s; s = (s - 1) & S)
        {
            int ans = ww[s];
            for (int i = 0; i < n; i++)
                if (s >> i & 1) ans += w[T][i];
            dp[T | s] = min(dp[T | s], dp[T] + ans);
        }
    }
    printf("%d\n", dp[U]);
}