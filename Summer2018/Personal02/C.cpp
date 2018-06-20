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
const int mod = 1e8 + 7;
const double eps = 1e-6;

const int maxn = 1 << 18;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    auto Pow = [](ll a, ll n, ll p) {
        ll t = 1;
        for (; n; n >>= 1, (a *= a) %= p)
            if (n & 1) (t *= a) %= p;
        return t;
    };
    vector<ll> f(maxn), inv(maxn);
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % mod;
    inv[maxn - 1] = Pow(f[maxn - 1], mod - 2, mod);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

    auto C = [&](int n, int m) { return f[n] * inv[m] % mod * inv[n - m] % mod; };
    ll m, n, p, q;
    while (cin >> m >> n >> p >> q)
    {
        ll ans = (C(m + n, n) * C(m - p + q, q) % mod - C(n + m - p, n) * C(m + q, m) % mod + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
