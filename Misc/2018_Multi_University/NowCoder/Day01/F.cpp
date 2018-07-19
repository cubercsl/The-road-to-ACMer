#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 1 << 10;

ll C[N][N];
ll B[N], Inv[N];
ll Tmp[N];
ll n;

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= MOD)
        if (n & 1) (t *= a) %= MOD;
    return t;
}

void Init()
{
    //预处理组合数
    for (int i = 0; i < N; i++)
    {
        C[i][0] = C[i][i] = 1;
        if (i == 0) continue;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j] % MOD + C[i - 1][j - 1] % MOD) % MOD;
    }
    //预处理逆元
    Inv[1] = 1;
    for (int i = 2; i < N; i++)
        Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;
    //预处理伯努利数
    B[0] = 1;
    for (int i = 1; i < N; i++)
    {
        ll ans = 0;
        if (i == N - 1) break;
        for (int j = 0; j < i; j++)
        {
            ans += C[i + 1][j] * B[j];
            ans %= MOD;
        }
        ans *= -Inv[i + 1];
        ans = (ans % MOD + MOD) % MOD;
        B[i] = ans;
    }
}

ll Work(int k)
{
    ll ans = Inv[k + 1];
    ll sum = 0;
    for (int i = 1; i <= k + 1; i++)
    {
        sum += C[k + 1][i] * Tmp[i] % MOD * B[k + 1 - i] % MOD;
        sum %= MOD;
    }
    ans *= sum;
    ans %= MOD;
    return ans;
}

ll sum(int n, int k)
{
    if (n < 0) return 0;
    n %= MOD;
    Tmp[0] = 1;
    for (int i = 1; i < N; i++)
        Tmp[i] = Tmp[i - 1] * (n + 1) % MOD;
    return Work(k);
}

int a[N];

int main()
{
    Init();
    int n;
    while (~scanf("%d", &n))
    {
        a[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        sort(a + 1, a + n + 1);
        ll p = 1;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll tmp = (Pow(a[i], n - i + 2) - Pow(a[i - 1], n - i + 2) + MOD) % MOD;
            ll s = (sum(a[i] - 1, n - i + 1) - sum(a[i - 1] - 1, n - i + 1) + MOD) % MOD;
            tmp = (tmp - s + MOD) % MOD;
            ans = (ans + p * tmp % MOD) % MOD;
            p = p * a[i] % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}