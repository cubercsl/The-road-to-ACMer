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

ll pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= m)
        if (n & 1) (t *= a) %= m;
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll n = (r - l + 1) / k;
        ll m = (r - l + 1) % k;

        ll ans = 1;
        for (int i = 1; i < k; i++)
            if (__gcd(l + i, k) == 1) (ans *= ((l + i) % k)) %= k;
        ans = pow(ans, n, k);
        for (int i = 0; i < m; i++)
            if (__gcd(l + i, k) == 1) (ans *= ((l + i) % k)) %= k;
        cout << "Case #" << ++kase << ": ";
        cout << ans << endl;
    }
    return 0;
}