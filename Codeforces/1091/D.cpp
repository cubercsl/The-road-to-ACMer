#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20;
const int p = 119 << 23 | 1;
typedef long long ll;
ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}
ll f[maxn];
ll inv[maxn];
int main()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
    ll n;
    cin >> n;
    ll ans = (n * f[n] + 1) % p;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans - f[n] * inv[i] % p);
        ans = (ans + p) % p;
    }
    cout << ans << endl;
}