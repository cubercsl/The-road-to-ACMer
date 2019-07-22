#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e3 + 5;
int a[maxn];
typedef long long ll;

ll Pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll tmp = 2LL * a[i] % mod;
            for (int j = 1; j <= n; j++)
            {
                if (j == i) continue;
                ll x = (1LL * a[i] * a[i] % mod - 1LL * a[j] * a[j] % mod + mod) % mod;
                tmp = tmp * x % mod;
            }
            ans = (ans + Pow(tmp, mod - 2)) % mod;
        }
        if (n % 2 == 0) ans = mod - ans;
        printf("%lld\n", ans);
    }
}
