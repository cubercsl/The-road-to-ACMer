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
const ll mod = 998244353;
const double eps = 1e-6;

ll Pow(ll a, ll b)
{
    ll ret = 1;
    for (; b; (b & 1) ? (ret = ret * a % mod) : 0, b >>= 1, a = a * a % mod)
        ;
    return ret;
}
ll fact[10000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll a, b, c;
    fact[0] = 1;
    for (ll i = 1; i < 6000; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    while (cin >> a >> b >> c)
    {
        ll tmp = 1, tot = 1, ans = 1;
        for (ll i = min(a, b), j = max(a, b), k = 1; i > 0; i--, j--, k++)
        {
            tmp *= (i * j) % mod;
            tmp %= mod;
            tot += tmp * Pow(fact[k], mod - 2);
            tot %= mod;
        }
        ans *= tot;
        ans %= mod;
        tmp = tot = 1;
        for (ll i = min(a, c), j = max(a, c), k = 1; i > 0; i--, j--, k++)
        {
            tmp *= (i * j) % mod;
            tmp %= mod;
            tot += tmp * Pow(fact[k], mod - 2);
            tot %= mod;
        }
        ans *= tot;
        ans %= mod;
        tmp = tot = 1;
        for (ll i = min(c, b), j = max(c, b), k = 1; i > 0; i--, j--, k++)
        {
            tmp *= (i * j) % mod;
            tmp %= mod;
            tot += tmp * Pow(fact[k], mod - 2);
            tot %= mod;
        }
        ans *= tot;
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}
