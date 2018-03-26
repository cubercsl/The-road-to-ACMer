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
const int mod = (119 << 23) + 1;
const double eps = 1e-6;

ll frac(int x)
{
    ll ret = 1;
    for (int i = 1; i <= x; i++) (ret *= i) %= mod;
    return ret;
}

ll Pow(ll a, ll n)
{
    ll ret = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (ret *= a) %= mod;
    return ret;
}

ll C(ll n, ll m) { return frac(n) * Pow(frac(m) * frac(n - m) % mod, mod - 2) % mod; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll n, m, k;
    while (cin >> n >> m >> k)
    {
        if (n <= m)
            cout << 0 << endl;
        else
            cout << Pow(n - m, k) * C(n, m) % mod << endl;
    }
    return 0;
}