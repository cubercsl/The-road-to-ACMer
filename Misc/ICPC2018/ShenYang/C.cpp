#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1 << 17;
int prime[maxn], tot, mu[maxn];
bool check[maxn];
void calmu()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i]) prime[tot++] = i, mu[i] = -1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
}

typedef __int128 LL;
LL Pow(LL a, LL n, LL p)
{
    LL t = 1;
    for (; n; n >>= 1, a = (a * a) % p)
        if (n & 1)
            t = t * a % p;
    return t;
}
LL f(LL x, LL p)
{
    LL ret = (Pow(x, 4, p) + 4 * Pow(x, 3, p) + 5 * Pow(x, 2, p) + 2 * x) % p;
    return ret;
}
void work(LL n, LL p)
{
    p *= 12;
    LL ret = f(n, p);

    for (LL i = 2; i * i <= n; i++)
    {
        LL x = n / (i * i);

        ret = ret + (LL)mu[i] * Pow(i, 4, p) * (2 * (n - x * i * i + 1) * (x * (x + 1) * (2 * x + 1) % p) % p + i * i * f(x - 1, p) % p) % p;

        ret = (ret + p) % p;
    }
    ll ans = ret / 12;
    printf("%lld\n", ans);
}

int main()
{
    ll n, p;
    calmu();
    while (~scanf("%lld%lld", &n, &p))
        work(n, p);
    return 0;
}