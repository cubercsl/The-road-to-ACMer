#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1 << 12;
const int mod = 1e9 + 7;
ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

ll dp[maxn << 1][maxn << 1];
const int SIZE = maxn;
// dp[第 i 个][A 比 B 多少个]

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i <= (n + m) * 2; i++)
            for (int j = 0; j <= n + SIZE; j++) dp[i][j] = 0;
        dp[0][SIZE] = 1;
        for (int i = 0; i < (n + m) * 2; i++)
            for (int j = -m; j <= n; j++)
                if (dp[i][j + SIZE])
                {
                    // A
                    if (j + 1 <= n)
                        (dp[i + 1][j + 1 + SIZE] += dp[i][j + SIZE]) %= mod;
                    // B
                    if (j - 1 >= -m)
                        (dp[i + 1][j - 1 + SIZE] += dp[i][j + SIZE]) %= mod;
                }
        printf("%lld\n", dp[2 * (n + m)][SIZE]);
    }
}