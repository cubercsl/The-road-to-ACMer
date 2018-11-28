#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1 << 17;
ll a[N], b[N], p[N];
ll Pow(ll a, ll n = mod - 2)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

namespace segment_tree
{
ll s[N << 2], t[N << 2];
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
int n;

inline void pushup(int o) { s[o] = (s[lson] + s[rson]) % mod; }

inline void pushdown(int o)
{
    if (t[o] == 1) return;
    s[lson] = s[lson] * t[o] % mod;
    s[rson] = s[rson] * t[o] % mod;
    t[lson] = t[lson] * t[o] % mod;
    t[rson] = t[rson] * t[o] % mod;
    t[o] = 1;
}

void build(int l, int r, int o)
{
    t[o] = 1;
    if (l == r)
    {
        if (l == n)
            s[o] = b[l];
        else
            s[o] = b[l] * 2LL * p[n - 1 - l] % mod;
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(o);
}

void update(int L, int R, int x, int l, int r, int o)
{
    if (L <= l && r <= R)
    {
        t[o] = t[o] * x % mod;
        s[o] = s[o] * x % mod;
        return;
    }
    pushdown(o);
    const int m = l + r >> 1;
    if (L <= m) update(L, R, x, Lson);
    if (m < R) update(L, R, x, Rson);
    pushup(o);
}

} // namespace segment_tree

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    p[0] = b[0] = 1;
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] * a[i] % mod;
    for (int i = 1; i <= n; i++) p[i] = 3LL * p[i - 1] % mod;
    segment_tree::n = n;
    segment_tree::build(1, n, 1);
    dbg(segment_tree::s[1]);
    for (int i = 0, x, y; i < q; i++)
    {
        scanf("%d%d", &x, &y);
        segment_tree::update(x, n, 1LL * y * Pow(a[x]) % mod, 1, n, 1);
        a[x] = y;
        printf("%lld\n", segment_tree::s[1]);
    }
    return 0;
}