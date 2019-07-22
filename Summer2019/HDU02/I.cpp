#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int cnt[N];
int prime[N], mu[N], sz;
bool check[N];
const int mod = 1e9 + 7;

void init()
{
    mu[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!check[i]) prime[sz++] = i, mu[i] = -1;
        for (int j = 0; j < sz; j++)
        {
            if (i * prime[j] >= N) break;
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

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll f[N];
ll F[N];

int main()
{
    init();
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        memset(f, 0, sizeof(f));
        memset(F, 0, sizeof(F));
        int m = INT_MAX;
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            cnt[x]++;
            if (m > x) m = x;
        }
        for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for (int i = 1; i <= m; i++)
        {
            F[i] = 1;
            for (int j = 1;; j++)
            {
                int t = cnt[min((j + 1) * i - 1, N - 1)] - cnt[j * i - 1];
                F[i] = F[i] * Pow(j, t) % mod;
                if ((j + 1) * i >= N) break;
            }
        }
        for (int i = 1; i <= m; i++)
            for (int j = i; j <= m; j += i)
                (f[i] += 1LL * mu[j / i] * F[j] % mod) %= mod;
        for (int i = 1; i < N; i++) f[i] = (f[i] + mod) % mod;
        ll ans = 0;
        for (int i = 2; i <= m; i++)
            ans = (ans + f[i]) % mod;
        printf("Case #%d: %lld\n", ++kase, ans);
    }
}