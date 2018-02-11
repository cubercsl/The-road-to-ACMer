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

inline void Mod(int& a)
{
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

void fwt(vector<int>& f, int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                Mod(f[j ^ (1 << i)] = l + r);
                Mod(f[j] = l - r);
            }
}

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; (a *= a) %= mod, n >>= 1)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int N;
    while (~scanf("%d", &N))
    {
        int n = 1;
        while (n < N) n <<= 1;
        ll inv = Pow(n, mod - 2);
        vector<int> a(n), b(n);
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        for (int i = 0; i < N; i++) scanf("%d", &b[i]);
        fwt(a, n), fwt(b, n);
        for (int i = 0; i < n; i++) a[i] = (1LL * a[i] * b[i]) % mod;
        fwt(a, n);
        for (int i = 0; i < n; i++) a[i] = (1LL * a[i] * inv) % mod;
        for (int i = 0; i < N; i++) printf("%d%c", a[i], i == N - 1 ? '\n' : ' ');
    }
    return 0;
}
