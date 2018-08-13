#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
int prime[maxn], tot, mu[maxn], sum[maxn], phi[maxn];
int inv[maxn];
bool check[maxn];
int p;
void getprime()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
            prime[tot++] = i, mu[i] = -1, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    for (int i = 1; i < maxn; i++) sum[i] = sum[i - 1] + mu[i];
}
ll cal(int n, int m) // n小
{
    int pos;
    ll ans = 0;
    for (int i = 1; i <= n; i = pos + 1)
    {
        pos = min(n / (n / i), m / (m / i));
        ans += 1LL * (sum[pos] - sum[i - 1] + p) % p * (n / i) % p * (m / i) % p;
        ans %= p;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    getprime();
    int T;
    scanf("%d", &T);
    int m, n;
    while (T--)
    {
        scanf("%d%d%d", &m, &n, &p);
        if (n > m) swap(n, m);
        inv[1] = 1;
        for (int i = 2; i <= n; i++) inv[i] = 1LL * (p - p / i) * inv[p % i] % p;
        ll ans = cal(n, m);
        for (int i = 2; i <= n; i++)
        {
            ll tmp = cal(n / i, m / i) * i % p * inv[phi[i]] % p;
            ans = (ans + tmp) % p;
        }
        printf("%lld\n", ans);
    }
    return 0;
}