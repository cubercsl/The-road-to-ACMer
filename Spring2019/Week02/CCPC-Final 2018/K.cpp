#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll euler(ll n)
{
    ll rt = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            rt -= rt / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) rt -= rt / n;
    return rt;
}

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if (b)
        d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else
        x = 1, y = 0;
    return d;
}

ll inv(ll a, ll m)
{
    ll x, y;
    ll d = exgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}

inline ll Mul(ll a, ll b, ll m)
{
    if (m <= 1000000000)
        return a * b % m;
    else if (m <= 1000000000000ll)
        return (((a * (b >> 20) % m) << 20) + (a * (b & ((1 << 20) - 1)))) % m;
    else
    {
        ll d = (ll)floor(a * (long double)b / m + 0.5);
        ll ret = (a * b - d * m) % m;
        if (ret < 0) ret += m;
        return ret;
    }
}

ll Pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, a = Mul(a, a, m))
        if (n & 1) t = Mul(t, a, m);
    return t;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ll n, a;
        scanf("%lld%lld", &n, &a);
        ll t = sqrt(n);
        ll p = -1, q = -1;
        for (ll i = t; i > 0; i--)
        {
            if (n % i == 0)
            {
                p = i;
                q = n / i;
                break;
            }
        }
        assert(p > 0 && q > 0);
        ll _n = (p - 1) * (q - 1);
        ll x = inv((1 << 30) + 3, _n);
        // cerr << x << endl;
        printf("Case %d: %lld\n", ++kase, Pow(a, x, n));
    }
}
