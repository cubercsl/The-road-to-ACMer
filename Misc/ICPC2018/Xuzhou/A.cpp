#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, k, x = 0;
        scanf("%lld%lld", &n, &k);
        ll m = Pow(2, k);
        for (int i = 1; i < n; i++)
        {
            if (i & 1)
                x = x * (m - 1);
            else
                x = x * (m - 1) + (m - 2);
            x %= mod;
        }
        ll x1 = m * Pow(m - 1, n - 1) % mod;
        ll x2 = m * x % mod;
        printf("%lld\n", (x1 - x2 + mod) % mod);
    }
}