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

const int N = 1 << 17;
ll f[N];

inline ll inv(ll a) { return Pow(a, mod - 2); }
inline ll P(ll n, ll m) { return f[n] * inv(f[n - m]) % mod; }
inline ll C(ll n, ll m) { return P(n, m) * inv(f[m]) % mod; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll inv2 = Pow(2, mod - 2);
    ll inv4 = Pow(4, mod - 2);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll t, p;
        scanf("%lld%lld", &t, &p);
        p = abs(p);
        if (t < p)
        {
            printf("0\n");
            continue;
        }
        ll ans = 0LL;
        for (int k = 0; 2 * k <= t - p; k++)
        {
            ll temp = f[t];
            temp = temp * inv(f[p + k]) % mod;
            temp = temp * inv(f[k]) % mod;
            temp = temp * inv(f[t - p - 2 * k]) % mod;
            temp = temp * Pow(inv4, p) % mod;
            temp = temp * Pow(inv2, t - p - 2 * k) % mod;
            temp = temp * Pow(inv(16), k) % mod;
            ans = (ans + temp) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
