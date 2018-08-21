#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int p = 119 << 23 | 1;
const int maxn = 1e7 + 5;
ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

ll f[maxn];

int main()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * 2) % p;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll a, b, c, d;
        ll ans = 0;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if (d > 1) ans += (((((f[d] - d - 1) % p) * f[a] % p) * f[b] % p) * f[c] % p);
        ans %= p;
        if (d > 0 && b > 0) ans += ((d * (f[b] - 1) % p) * f[a] % p * f[c]) % p;
        ans %= p;
        if (b > 1 && c > 0) ans += ((f[b] - 1 - b) * (f[c] - 1) % p * f[a]) % p;
        ans %= p;
        ans = (Pow(2, a + b + c + d, p) - ans) % p;
        ans = (ans + p) % p;
        printf("%lld\n", ans);
    }
    return 0;
}