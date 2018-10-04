#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int maxn = 1 << 17;
ll sumv[maxn << 2], addv[maxn << 2], mulv[maxn << 2];

inline void pushup(int o) { sumv[o] = sumv[lson] + sumv[rson]; }

inline void pushdown(int o, int m)
{
#define lm (m - (m >> 1))
#define rm (m >> 1)
    ll &k = mulv[o], &b = addv[o];
    if (k == 1 && b == 0) return;
    sumv[lson] = sumv[lson] * k + b * lm;
    sumv[rson] = sumv[rson] * k + b * rm;
    addv[lson] = addv[lson] * k + b;
    addv[rson] = addv[rson] * k + b;
    mulv[lson] = mulv[lson] * k;
    mulv[rson] = mulv[rson] * k;
    k = 1, b = 0;
#undef lm
#undef rm
}

void build(int l, int r, int o)
{
    addv[o] = 0, mulv[o] = 1;
    if (l == r)
    {
        scanf("%lld", &sumv[o]);
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(o);
}

void update(int L, int R, int k, int b, int l, int r, int o)
{
    if (L <= l && r <= R)
    {
        sumv[o] = sumv[o] * k + 1LL * b * (r - l + 1);
        mulv[o] *= k;
        addv[o] = addv[o] * k + b;
        return;
    }
    pushdown(o, r - l + 1);
    const int m = l + r >> 1;
    if (L <= m) update(L, R, k, b, Lson);
    if (m < R) update(L, R, k, b, Rson);
    pushup(o);
}

ll query(int L, int R, int l, int r, int o)
{
    if (L <= l && r <= R) return sumv[o];
    pushdown(o, r - l + 1);
    const int m = l + r >> 1;
    ll ans = 0;
    if (L <= m) ans += query(L, R, Lson);
    if (m < R) ans += query(L, R, Rson);
    return ans;
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        build(1, n, 1);
        for (int i = 0, op, x, y, k, b; i < m; i++)
        {
            scanf("%d%d%d", &op, &x, &y);
            if (op == 1)
            {
                scanf("%d%d", &k, &b);
                update(x, y, k, b, 1, n, 1);
            }
            else
                printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
}