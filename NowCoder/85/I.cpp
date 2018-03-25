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

const int maxn = 200010;

ll Pow(ll a, ll n, ll p)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}

ll f[maxn];
ll inv[maxn]; // 阶乘的逆元
void CalFact(ll p)
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = Pow(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}
ll C(int n, int m, int p) { return f[n] * inv[m] % p * inv[n - m] % p; }
ll K(int n, int p) { return C(n * 2, n, p) * Pow(n + 1, p - 2, p) % p; }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    cin >> T;
    CalFact(mod);
    while (T--)
    {
        cout << "Case #" << ++kase << ": ";
        ll n;
        cin >> n;
        ll ans = (K(n, mod) - K(n - 1, mod) + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}