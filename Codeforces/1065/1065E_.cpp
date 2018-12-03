ll pow2(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll x)
{
    return pow2(x, mod - 2);
}
ll k[MAX], dp[MAX][2];
void go()
{
    ll n, m, a, i, ans;
    while (read(n, m, a))
    {
        for (i = 1; i <= m; i++) read(k[i]);
        dp[m + 1][0] = pow2(a, n);
        dp[m + 1][1] = 0;
        for (i = m; i; i--)
        {
            dp[i][0] = (dp[i + 1][0] + dp[i + 1][1] * pow2(a, k[i]) % mod) % mod;
            dp[i][1] = (dp[i + 1][1] + dp[i + 1][0] * pow2(a, mod - 1 - k[i]) % mod) % mod;
        }
        ans = (dp[1][0] + dp[1][1]) % mod;
        ans = ans * (inv(pow2(2, m))) % mod;
        printf("%lld\n", ans);
    }
}