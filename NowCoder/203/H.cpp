#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int p = 1e9 + 7;
const int N = 1 << 17;
ll f[N], inv[N];
ll C(int n, int m) { return f[n] * inv[m] % p * inv[n - m] % p; }
ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

int main()
{
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % p;
    inv[N - 1] = Pow(f[N - 1], p - 2, p);
    for (int i = N - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i < n; i++) scanf("%*d%*d");
        printf("%lld\n", C(n - 1, m - 1) * f[m] % p);
    }
}