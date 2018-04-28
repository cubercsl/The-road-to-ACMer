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
 
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}
 
inline ll inv(ll x) { return Pow(x, mod - 2); }
 
const int N = 1 << 10;
ll a[N];
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        ll k;
        scanf("%d%lld", &n, &k);
        vector<ll> v;
        ll tmp = 1;
        v.pb(tmp);
        for (int i = 1; i <= n; i++)
        {
            tmp = tmp * (k - i + 1) % mod;
            tmp = tmp * inv(i) % mod;
            tmp = (-tmp + mod) % mod;
            v.pb(tmp);
        }
        for (int i = 1; i <= n; i++) scanf("%lld", a + i);
        for (int i = 1; i <= n; i++)
        {
            ll ans = 0;
            for (int j = i, k = 0; j; j--, k++) ans = (ans + v[k] * a[j]) % mod;
            printf("%lld%c", ans, " \n"[i == n]);
        }
    }
    return 0;
}