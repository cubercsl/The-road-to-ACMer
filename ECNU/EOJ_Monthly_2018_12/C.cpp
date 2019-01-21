#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2005;
ll dp[2][N][11][11];

char s[N];
const int mod = 1e9 + 7;

int main()
{
    scanf("%s", s);
    dp[0][0][10][10] = 1;
    int m = strlen(s);
    for (int i = 0; s[i]; i++)
    {
        memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
        for (int j = 0; j <= i; j++)
            for (int x = 0; x < 11; x++)
                for (int y = 0; y < 11; y++)
                    if (dp[i & 1][j][x][y])
                    {
                        (dp[i & 1 ^ 1][j][x][y] += dp[i & 1][j][x][y]) %= mod;
                        (dp[i & 1 ^ 1][j + 1][y][s[i] - '0'] += dp[i & 1][j][x][y]) %= mod;
                    }
    }
    int q;
    scanf("%d", &q);
    int n, x, y;
    while (q--)
    {
        scanf("%d%s", &n, s);
        x = s[0] - '0', y = s[1] - '0';
        printf("%lld\n", n < N ? dp[m & 1][n][x][y] : 0);
    }
}