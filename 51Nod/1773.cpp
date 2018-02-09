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

ll inv2;

template <class T>
inline bool scan_d(T& ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void out(T x)
{
    if (x > 9) out(x / 10);
    putchar(x % 10 + '0');
}

void fwt(vector<ll>& a, int l, int r)
{
    if (l + 1 == r) return;
    int mid = l + r >> 1, len = mid - l;
    fwt(a, l, mid);
    fwt(a, mid, r);
    for (int i = l; i < mid; i++)
    {
        ll u = a[i], v = a[i + len];
        a[i] = (u + v) % mod;
        a[i + len] = (u - v + mod) % mod;
    }
}

void ifwt(vector<ll>& a, int l, int r)
{

    if (l + 1 == r) return;
    int mid = l + r >> 1, len = mid - l;
    for (int i = l; i < mid; i++)
    {
        ll u = a[i], v = a[i + len];
        a[i] = (u + v) * inv2 % mod;
        a[i + len] = ((u - v) * inv2 % mod + mod) % mod;
    }
    ifwt(a, l, mid);
    ifwt(a, mid, r);
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
    int n, t;
    inv2 = Pow(2, mod - 2);
    scanf("%d%d", &n, &t);
    vector<ll> a(1 << n), b(1 << n);
    for (auto& t : a) scan_d(t);
    b[0] = 1;
    for (int i = 0; i < n; i++) b[1 << i] = 1;
    fwt(a, 0, 1 << n);
    fwt(b, 0, 1 << n);
    for (int i = 0; i < (1 << n); i++) (a[i] *= Pow(b[i], t)) %= mod;
    ifwt(a, 0, 1 << n);
    for (auto& t : a) out(t), putchar(' ');

    return 0;
}