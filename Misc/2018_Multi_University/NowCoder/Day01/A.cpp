#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int mod = 1e9 + 7;
typedef long long ll;
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll f[maxn];
ll inv[maxn]; // 阶乘的逆元
void CalFact()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % mod;
    inv[maxn - 1] = Pow(f[maxn - 1], mod - 2);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
ll C(int n, int m) { return f[n] * inv[m] % mod * inv[n - m] % mod; }
ll F(int n, int k) { return C(n - 1, k - 1) * C(n, k - 1) % mod * Pow(k, mod - 2) % mod; }
int main()
{
    CalFact();
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        if (n > m) swap(n, m);
        printf("%lld\n", F(n + m + 1, n + 1));
    }
}