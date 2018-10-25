#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int mod = 1e9 + 7;
bool check[maxn];
int tot, phi[maxn], prime[maxn];
void getprime()
{
    phi[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i]) prime[tot++] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[i]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
long long Pow(long long a, long long x)
{
    long long t = 1;
    for (; x; a = a * a % mod, x >>= 1)
        if (x & 1) t = t * a % mod;
    return t;
}
int main()
{
    int n, m, c;
    getprime();
    while (~scanf("%d%d%d", &n, &m, &c))
    {
        long long squ = n * n;
        long long ans = 0;
        for (int i = 1; i * i <= m; i++)
        {
            if (m % i == 0)
            {
                (ans += phi[m / i] * Pow(c, squ * i) % mod) %= mod;
                if (i * i != m) (ans += phi[i] * Pow(c, squ * m / i) % mod) %= mod;
            }
        }
        // cerr << m << endl;
        // cerr << Pow(m, mod - 2) << endl;
        ans = ans * Pow(m, mod - 2) % mod;
        printf("%lld\n", ans);
    }
}
