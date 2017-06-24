#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
ll dp[maxn];

ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0 && b == 0)return -1;
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll mod_reverse(ll a, ll n)
{
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if (d == 1) return (x % n + n) % n;
    else return -1;
}

void init()
{
    dp[0] = 1;
    for (int i = 1; i < maxn; i++)
        dp[i] = (dp[i - 1] * i + mod) % mod;
    for (int i = 1; i < maxn; i++)
        dp[i] = (dp[i - 1] * dp[i] + mod) % mod;
}

int main()
{
    init();
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0)
            n = 1;
        if (m == 0)
            m = 1;
        ll ans = dp[m] % mod;
        ll tmp = mod_reverse(dp[n - 1] % mod , mod);
        ans = (ans * tmp + mod) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}
