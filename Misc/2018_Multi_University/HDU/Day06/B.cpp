#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 21;
typedef long long ll;
const int p = 1e9 + 7;
ll fib[maxn];
int N, k;

ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

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

ll f[maxn];
ll inv[maxn]; // 阶乘的逆元
void CalFact()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}
inline ll C(int n, int m) { return f[n] * inv[m] % p * inv[n - m] % p; }

inline ll F(ll n) { return C(n + k - 1, k - 1); }

inline ll fuck(ll n)
{
    ll ret = 0;
    for (int d = 1; d * d <= n; d++)
        if (n % d == 0)
        {
            int dd = n / d;
            ret = ret + mu[d] * F(dd);
            ret += p;
            ret %= p;
            if (dd != d)
            {
                ret = ret + mu[dd] * F(d);
                ret += p;
                ret %= p;
            }
        }
    return ret;
}

inline ll gao(ll n)
{
    ll ret = fuck(n) * (Pow(2, fib[N / n], p) - 1) % p;
    // cerr << ret << endl;
    return ret;
}

inline ll Inv(ll x) { return Pow(x, p - 2, p); }

int main()
{
    calmu();
    CalFact();
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < maxn; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % (p - 1);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &k);
        ll t = 0;

        for (int n = 1; n * n <= N; n++)
        {
            if (N % n == 0)
            {
                t += gao(n);
                t %= p;
                if (N / n != n) t += gao(N / n);
                t %= p;
            }
        }
        ll ans = t * Inv(C(N + k - 1, k - 1)) % p;
        printf("%lld\n", ans);
    }
}