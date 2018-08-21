#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll inv2 = mod - mod / 2;

ll Pow(ll a, ll n = mod - 2)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

void fwt(int* f, const int& m, bool rev = false)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = (l + r) % mod;
                f[j] = (l - r + mod) % mod;
            }
    if (rev)
    {
        ll inv = 1;
        for (int i = 0; i < n; i++) (inv *= inv2) %= mod;
        for (int i = 0; i < m; i++) f[i] = 1LL * f[i] * inv % mod;
    }
}

const int N = 1 << 18;
int a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    fwt(a, n), fwt(b, n);
    for (int i = 0; i < n; i++) a[i] = 1LL * b[i] * Pow(a[i]) % mod;
    fwt(a, n, 1);
    for (int i = 0; i < n; i++) printf("%d\n", a[i]);
}