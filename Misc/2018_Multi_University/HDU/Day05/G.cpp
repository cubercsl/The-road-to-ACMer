#include <bits/stdc++.h>
using namespace std;

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

typedef long long ll;
const int N = 1 << 17;
ll minv[N << 2];

inline void pushup(int o)
{
    minv[o] = min(minv[lson], minv[rson]);
}

void build(int l, int r, int o)
{
    if (l == r)
    {
        minv[o] = 0;
        return;
    }
    int m = l + r >> 1;
    build(Lson), build(Rson);
    pushup(o);
}

void update(int L, int R, ll v, int l, int r, int o)
{
    if (minv[o] >= v) return;
    if (l == r)
    {
        minv[o] = v;
        return;
    }
    int m = l + r >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(o);
}

ll query(int p, int l, int r, int o)
{
    if (l == r) return minv[o];
    int m = l + r >> 1;
    if (p <= m) return query(p, Lson);
    return query(p, Rson);
}

static unsigned int x, y, z;
unsigned int gao()
{
    x = x ^ (x << 11);
    x = x ^ (x >> 4);
    x = x ^ (x << 5);
    x = x ^ (x >> 14);
    unsigned int w = x ^ (y ^ z);
    x = y;
    y = z;
    z = w;
    return z;
}
const int mod = 1 << 30;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, a, b, c;
        scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
        x = a, y = b, z = c;
        build(1, n, 1);
        for (int i = 0; i < m; i++)
        {
            int l = gao() % n + 1;
            int r = gao() % n + 1;
            int v = gao() % mod;
            // cerr << l << " " << r << " " << v << endl;
            if (l > r) swap(l, r);
            update(l, r, v, 1, n, 1);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans ^= i * query(i, 1, n, 1);
        printf("%lld\n", ans);
    }
}