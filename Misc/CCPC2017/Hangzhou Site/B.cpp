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
const int mod = 998244353;
const double eps = 1e-6;

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll inv(ll a) { return Pow(a, mod - 2); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ll ans = 1;
        vector<ll> p(n), q(n), _p(n);
        for (int i = 0; i < n; i++) cin >> p[i] >> q[i];
        for (int i = 0; i < n; i++) _p[i] = inv(p[i]);
        for (int i = 0; i < n; i++) (ans *= Pow(p[i], q[i])) %= mod;
        // for (int i = 0; i < (1 << n); i++)
        // {
        //     ll x = 1;
        //     ll cnt = 1;
        //     for (int j = 0; j < n; j++)
        //         if (i >> j & 1) x = (x * (1 - _p[j] + mod) % mod) % mod, (cnt *= q[j]) %= mod;
        //     ans += (x * cnt % mod * m % mod);
        //     ans %= mod;
        // }
        for (int i = 0; i < n; i++)
        {
            ans = ans * ((q[i] * (p[i] - 1) % mod * _p[i] % mod + 1) % mod);
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}