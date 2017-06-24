#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll pow_mod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll Cm(ll n, ll m)
{
    ll a = 1, b = 1;
    if (m > n) return 0;
    while (m)
    {
        a = (a * n--) % mod;
        b = (b * m--) % mod;
    }
    return (a * pow_mod(b, mod - 2)) % mod;
}

ll Lucas(ll n, ll m)
{
    if (m == 0)
        return 1;
    return (Cm(n % mod, m % mod) * Lucas(n / mod, m / mod)) % mod;
}

int main()
{
    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        ll ans = (Lucas(a, b) * pow_mod(c, b)) % mod;
        cout << ans << endl;
    }
    return 0;
}
