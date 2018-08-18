#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 10;
const int mod = 1e9 + 7;
ll p[N];
ll dp[N][N];

ll Pow(ll a, ll n = mod - 2)
{
    a %= mod;
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    int n, m;
    ll inv100 = Pow(100);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", p + i), p[i] = p[i] * inv100 % mod;
    dp[0][0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * p[i] % mod;
            dp[i][0] += dp[i - 1][j] * (1 - p[i]) % mod;
            dp[i][j] = (dp[i][j] % mod + mod) % mod;
            ans += dp[i - 1][j] * (1 - p[i]) % mod * Pow(j, m) % mod;
        }
        dp[i][0] += dp[i - 1][0] * (1 - p[i]) % mod;
        dp[i][0] = (dp[i][0] % mod + mod) % mod;
    }
    for (int i = 1; i <= n; i++) ans += dp[n][i] * Pow(i, m) % mod;
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans);
}