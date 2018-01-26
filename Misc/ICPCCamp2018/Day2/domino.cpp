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

const int N = 2e3 + 5;

ll f[N], inv[N];
ll Pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= m)
        if (n & 1) (t *= a) %= m;
    return t;
}

inline ll C(int n, int m, int k) { return f[n] * inv[n - m] % k * inv[m] % k; }
inline ll F(int n, int m, int k) { return C(n + m - 1, m, k); }

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
        int x, y, m;
        scanf("%d%d%d", &x, &y, &m);
        int n = x + y;
        f[0] = 1;
        for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % m;
        inv[N - 1] = Pow(f[N - 1], m - 2, m);
        for (int i = N - 1; i; i--) inv[i - 1] = inv[i] * i % m;
        ll ans = 0;
        for (int i = (n & 1); i <= y; i += 2)
        {
            int k = n - i;
            ll a = C(k, x, m);
            ll b = F(k / 2 + 1, i, m);
            ans += (a * b) % m;
            ans %= m;
        }
        printf("%lld\n", ans);
    }
    return 0;
}