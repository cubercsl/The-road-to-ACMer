#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 119 << 23 | 1;

ll Pow(ll a, ll n = mod - 2)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    ll n, m, a;
    cin >> n >> m >> a;
    ll x = Pow(a, n), y = 0;
    vector<int> bb(m);
    for (auto& b : bb) cin >> b;
    reverse(bb.begin(), bb.end());
    for (auto& b : bb)
    {
        ll xx = (x + y * Pow(a, b) % mod) % mod;
        ll yy = (y + x * Pow(a, mod - 1 - b) % mod) % mod;
        swap(x, xx), swap(y, yy);
    }
    cerr << x << " " << y << endl;
    ll ans = (x + y) % mod * Pow(Pow(2, m)) % mod;
    cout << ans << endl;
}