#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2010;
const int mod = 1e9 + 7;
ll C[maxn][maxn];
void init()
{
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll f[maxn];

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++)
        {
            int sgn = 1;
            for (int j = i; ~j; j--)
            {
                (f[i] += 1LL * sgn * C[i][j] % mod * Pow(j, n) % mod) %= mod;
                f[i] = (f[i] + mod) % mod;
                sgn = -sgn;
            }
        }
        ll ans = 0;
        for (int i = 1; i < m; i++)
            for (int j = 1; i + j <= m; j++)
                ans = (ans + C[m][i] * f[i] % mod * C[m - i][j] % mod * f[j] % mod) % mod;
        printf("%lld\n", ans);
    }
}