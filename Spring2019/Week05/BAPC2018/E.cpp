#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;
const int N = 5e3 + 5;
typedef long long ll;
int a[N];
ll dp[N], inv[N];

ll Pow(ll a, ll n = mod - 2)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll res[N][N];

inline ll ask(int l, int r)
{
    if (l > r) return 1;
    return res[l][r];
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        int tot = 1;
        res[i][i - 1] = 1;
        for (int j = i; j <= n; j++)
        {
            res[i][j] = res[i][j - 1] * (j - i + 1) % mod;
            if (j != i && a[j] == a[j - 1])
                tot++;
            else
                tot = 1;
            res[i][j] = res[i][j] * inv[tot] % mod;
        }
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = ask(1, i);

        for (int j = 1; j <= i; j++)
            dp[i] = (dp[i] - dp[j - 1] * ask(j + 1, i) % mod + mod) % mod;
    }

    printf("%lld\n", dp[n]);
}