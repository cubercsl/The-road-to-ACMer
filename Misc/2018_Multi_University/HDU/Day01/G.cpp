#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
int main()
{
    ll a[65];
    ll p[65];
    p[0] = 1, a[0] = 0;
    for (int i = 1; i < 62; i++)
    {
        p[i] = p[i - 1] * 2;
        a[i] = a[i - 1] * 2 % mod + ((p[i - 1] % mod) * (p[i] % mod)) % mod + p[i - 1] % mod;
        a[i] %= mod;
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, ans = 0, t = 0;
        scanf("%lld", &n);
        for (int i = 61; i >= 1; i--)
        {
            if (n >= p[i] - 1)
            {
                n -= p[i] - 1;
                ans = ans + a[i - 1] + ((p[i - 1] % mod) * (n % mod)) % mod;
                ans %= mod;
                i++;
            }
        }
        printf("%lld\n", (ans + 1) % mod);
    }
    return 0;
}
