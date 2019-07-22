#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int inv2 = mod + 1 >> 1;
ll phi(ll n)
{
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

ll gao(ll x, ll d)
{
    ll ans = (x / d) * phi(x / d) % mod + ((x / d) == 1);
    ans %= mod;
    ans = d * d % mod * ans % mod * inv2 % mod;
    return ans;
}

ll solve(ll m, ll p)
{

    ll ans = 0;
    for (ll i = 1; i * i <= (p - 1); i++)
    {
        if ((p - 1) % i == 0)
        {
            (ans += gao(p - 1, i)) %= mod;
            if (i != (p - 1) / i) (ans += gao(p - 1, (p - 1) / i)) %= mod;
        }
    }
    ans = ((ans - (p * (p - 1) / 2)) % mod + mod) % mod;
    return ans * m % mod;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ll m, p;
        scanf("%lld%lld", &m, &p);
        printf("Case #%d: %lld\n", ++kase, solve(m, p));
    }
}