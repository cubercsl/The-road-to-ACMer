#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
const int maxn = 5e5 + 5;
typedef long long ll;
int a[maxn], b[maxn], c[maxn];
int LB[maxn], RB[maxn], LA[maxn], RA[maxn];
ll sum[maxn << 2], lazy[maxn << 2];
inline void pushup(int rt)
{
    sum[rt] = sum[lson] + sum[rson];
}
inline void pushdown(int rt, int len)
{
    if (!lazy[rt]) return;
    sum[lson] += 1LL * lson_len * lazy[rt];
    lazy[lson] += lazy[rt];
    sum[rson] += 1LL * rson_len * lazy[rt];
    lazy[rson] += lazy[rt];
    lazy[rt] = 0;
}
void build(int rt, int l, int r)
{
    lazy[rt] = 0;
    if (l == r)
    {
        sum[rt] = 0;
        return;
    }
    int m = l + r >> 1;
    build(lson, l, m);
    build(rson, m + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int L, int R, int x)
{
    if (L > R) return;
    int len = r - l + 1;
    if (L <= l && R >= r)
    {
        sum[rt] += 1LL * len * x;
        lazy[rt] += x;
        return;
    }
    pushdown(rt, len);
    int m = l + r >> 1;
    if (m >= L) update(lson, l, m, L, R, x);
    if (m + 1 <= R) update(rson, m + 1, r, L, R, x);
    pushup(rt);
}
ll query(int rt, int l, int r, int L, int R)
{
    if (L > R) return 0LL;
    if (L <= l && R >= r)
        return sum[rt];
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    ll ret = 0;
    if (m >= L) ret += query(lson, l, m, L, R);
    if (m + 1 <= R) ret += query(rson, m + 1, r, L, R);
    return ret;
}
int main()
{
    int d, na, nb, nc;
    while (~scanf("%d%d%d%d", &d, &na, &nb, &nc))
    {
        for (int i = 1; i <= na; i++) scanf("%d", a + i);
        for (int i = 1; i <= nb; i++) scanf("%d", b + i);
        for (int i = 1; i <= nc; i++) scanf("%d", c + i);
        int lc = 1, rc = 1;
        for (int i = 1; i <= nb; i++)
        {
            while (lc <= nc && c[lc] < b[i] - d) lc++;
            while (rc <= nc && c[rc] <= b[i] + d) rc++;
            LB[i] = lc;
            RB[i] = rc - 1;
        }
        lc = 1, rc = 1;
        for (int i = 1; i <= na; i++)
        {
            while (lc <= nc && c[lc] < a[i] - d) lc++;
            while (rc <= nc && c[rc] <= a[i] + d) rc++;
            LA[i] = lc;
            RA[i] = rc - 1;
        }
        build(1, 1, nc);
        ll ans = 0;
        LB[0] = 1;
        RB[0] = 0;
        b[0] = -1e9-10;
        int lb = 0, rb = 0;
        for (int i = 1; i <= na; i++)
        {
            while (lb <= nb && b[lb] < a[i] - d)
            {
                update(1, 1, nc, LB[lb], RB[lb], -1);
                lb++;
            }
            while (rb <= nb && b[rb] <= a[i] + d)
            {
                update(1, 1, nc, LB[rb], RB[rb], 1);
                rb++;
            }
            ans += query(1, 1, nc, LA[i], RA[i]);
        }
        printf("%lld\n", ans);
    }
}