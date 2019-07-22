#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20;
const int mod = 1e9 + 7;
int prime[maxn], tot;
int d[maxn], e[maxn], phi[maxn], mu[maxn];
bool check[maxn];
int f[maxn], sd[maxn];
void init()
{
    d[1] = 1, mu[1] = 1, phi[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            e[i] = 1, d[i] = 2, phi[i] = i - 1, mu[i] = -1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                e[i * prime[j]] = e[i] + 1;
                d[i * prime[j]] = d[i] / (e[i] + 1) * (e[i] + 2);
                phi[i * prime[j]] = phi[i] * prime[j];
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                e[i * prime[j]] = 1;
                d[i * prime[j]] = 2 * d[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    sd[0] = 0;
    for (int i = 1; i < maxn; i++) sd[i] = (sd[i - 1] + d[i]) % mod;
    for (int i = 1; i < maxn; i++)
        for (int j = i; j < maxn; j += i)
        {
            (f[j] += mu[j / i] * sd[i] % mod) %= mod;
            (f[i] += mod) %= mod;
        }
    for (int i = 1; i < maxn; i++)
        f[i] = ((f[i] + phi[i]) % mod + mod - 1) % mod;
    for (int i = 1; i < maxn; i++)
        (f[i] += f[i - 1]) %= mod;
}

int main()
{
    init();
    int n;
    while (~scanf("%d", &n)) printf("%d\n", f[n]);
}