#include <bits/stdc++.h>
using namespace std;

const int mod = 119 << 23 | 1;
const int G = 3;
int wn[20];

int Pow(int a, int n, int mod)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}

void ntt(int y[], int len, int on)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
    for (int h = 2, id = 1; h <= len; h <<= 1, id++)
    {
        for (int j = 0; j < len; j += h)
        {
            int w = 1;
            for (int k = j; k < j + h / 2; k++)
            {
                int u = y[k] % mod;
                int t = 1LL * w * (y[k + h / 2] % mod) % mod;
                y[k] = (u + t) % mod, y[k + h / 2] = ((u - t) % mod + mod) % mod;
                w = 1LL * w * wn[id] % mod;
            }
        }
    }
    if (on == -1)
    {
        int inv = Pow(len, mod - 2, mod);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = 1LL * y[i] * inv % mod;
    }
}

const int N = 1 << 20;
int fac[N] = {1};
int fac_[N];
int a[N];
int b[N];
int c[N];

int main()
{
    for (int i = 0; i < 20; i++) wn[i] = Pow(G, (mod - 1) / (1 << i), mod);
    for (int i = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
    fac_[N - 1] = Pow(fac[N - 1], mod - 2, mod);
    for (int i = N - 2; ~i; i--) fac_[i] = 1LL * fac_[i + 1] * (i + 1) % mod;
    int n;
    while (~scanf("%d", &n))
    {
        int t = 0;
        for (int i = 0; i <= n; i++) scanf("%d", c + i);
        int m;
        scanf("%d", &m);
        for (int i = 0, x; i < m; i++) scanf("%d", &x), (t += x) %= mod;
        int len = 1;
        t = mod - t;
        while (len <= n * 2) len <<= 1;
        for (int i = 0; i < len; i++) a[i] = i > n ? 0 : 1LL * c[n - i] * fac[n - i] % mod;
        for (int i = 0; i < len; i++) b[i] = i > n ? 0 : 1LL * Pow(t, i, mod) * fac_[i] % mod;
        ntt(a, len, 1);
        ntt(b, len, 1);
        for (int i = 0; i < len; i++) a[i] = 1LL * a[i] * b[i] % mod;
        ntt(a, len, -1);
        for (int i = 0; i <= n; i++) printf("%d%c", 1LL * a[n - i] * fac_[i] % mod, " \n"[i == n]);
    }
}