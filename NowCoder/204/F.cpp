#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int mod = 119 << 23 | 1;
const int N = 1 << 19;
const int G = 3;
int wn[20];

int Pow(int a, int n = mod - 2)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}

void getwn()
{
    for (int i = 0; i < 20; i++) wn[i] = Pow(G, (mod - 1) / (1 << i));
}
void change(int y[], int len)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}
void ntt(int y[], int len, int on)
{
    change(y, len);
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
        int inv = Pow(len);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = 1LL * y[i] * inv % mod;
    }
}

int f[N], a[N], b[N];
int d[N], ans[N];

int main()
{
    getwn();
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = 1LL * f[i - 1] * i % mod;
    int n;
    scanf("%d", &n);
    d[n - 1] = Pow(f[n - 1]);
    for (int i = n - 2; ~i; i--) d[i] = 1LL * d[i + 1] * (i + 1) % mod;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] = 1LL * a[i] * f[i] % mod;
    ntt(a, N, 1);
    for (int i = 0; i < N; i++) a[i] = 1LL * a[i] * a[i] % mod;
    ntt(a, N, -1);
    ntt(d, N, 1);
    for (int i = 0; i < N; i++) d[i] = 1LL * d[i] * d[i] % mod;
    ntt(d, N, -1);
    for (int i = 0; i < n; i++) ans[i] = 1LL * a[n - 1 + i] * d[i] % mod;
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
    return 0;
}