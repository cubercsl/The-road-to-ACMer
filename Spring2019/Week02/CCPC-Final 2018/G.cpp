#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

ll f[maxn], inv[maxn];
ll Pow(ll a, ll n)
{
    ll t = 1;
    for(;n;n >>= 1,a = a * a % mod)
        if(n & 1) t = t * a % mod;
    return t;
}
void pre()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = f[i - 1] * i % mod;
    inv[maxn - 1] = Pow(f[maxn - 1], mod - 2);
    for (int i = maxn - 2;  ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
ll C(ll n, ll m)
{
    if (n < m) return 0;
    return f[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    int T, kase = 0;
    ll n, m;
    scanf("%d", &T);
    pre();
    while(T--)
    {
        scanf("%lld%lld", &n, &m);
        ll ans = (C(n, 4) + C(n, 3)) % mod * (C(m, 4) + C(m, 3)) % mod;
        printf("Case %d: %lld\n", ++kase, ans);
    }
}
