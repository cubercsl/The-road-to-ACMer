#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
long long a[N];
long long x[N], y[N];
void gen(int n)
{
    long long c, d, e1, e2, f;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &x[1], &y[1], &c, &d, &e1, &e2, &f);
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            x[i] = (c * x[i - 1] % f + d * y[i - 1] % f + e1) % f;
            y[i] = (d * x[i - 1] % f + c * y[i - 1] % f + e2) % f;
        }
        a[i] = (x[i] + y[i]) % f;
    }
}
const int mod = 1e9 + 7;
long long p[N], inv[N];
long long s[N];
long long Pow(long long a, long long n)
{
    long long t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        gen(n);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                s[i] = k;
            else
                s[i] = 1LL * i * (Pow(i, k) - 1) % mod * inv[i - 1] % mod;
            s[i] = (s[i] + s[i - 1]) % mod;
            ans = (ans + a[i] * (n - i + 1) % mod * s[i] % mod) % mod;
        }
        printf("%lld\n", ans);
    }
}