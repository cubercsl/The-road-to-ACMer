#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll n;
    ll inv2 = (mod - mod / 2) % mod;
    while (~scanf("%lld", &n))
    {
        ll t = 1;
        if (n == 2)
            puts("1");
        else if (n == 3)
            puts("3");
        else
        {
            while (t < n) t <<= 1;
            t >>= 1;
            // printf("t = %lld\n", t);
            ll ans = (t % mod * ((t - 1) % mod) % mod * inv2 % mod);
            // cout << ans << endl;
            ll tmp = 1;
            ans = (ans + n - 1) % mod;
            n--;
            for (; n != 1; n >>= 1, tmp = (tmp << 1) % mod)
                if (n & 1) ans = (ans + (tmp * tmp % mod + inv2 * tmp % mod * (tmp - 1) % mod) % mod) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
