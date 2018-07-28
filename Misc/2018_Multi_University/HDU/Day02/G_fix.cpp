#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
const int INF = 0x3f3f3f3f;

namespace BIT
{
int bit[N];
void init() { memset(bit, 0, sizeof(bit)); }
void update(int x)
{
    for (int i = x; i < N; i += i & -i) ++bit[i];
}
int query(int l, int r)
{
    int ret = 0;
    for (int i = r; i; i -= i & -i) ret += bit[i];
    for (int i = l - 1; i; i -= i & -i) ret -= bit[i];
    return ret;
}
}; // namespace BIT

namespace SegmentTree
{
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

int b[N << 2], v[N << 2], t[N << 2];

inline void pushup(int o) { v[o] = min(v[lson], v[rson]); }

inline void pushdown(int o)
{
    if (!t[o]) return;
    t[lson] += t[o], t[rson] += t[o];
    v[lson] -= t[o], v[rson] -= t[o];
    t[o] = 0;
}

void build(int l, int r, int o)
{
    t[o] = 0;
    if (l == r)
    {
        scanf("%d", &v[o]);
        b[l] = v[o];
        return;
    }
    int m = l + r >> 1;
    build(Lson), build(Rson);
    pushup(o);
}

void update(int L, int R, int l, int r, int o)
{
    if (v[o] == 1)
    {
        v[o] = INF;
        if (l == r)
        {
            v[o] = b[l];
            BIT::update(l);
            return;
        }
        pushdown(o);
        int m = l + r >> 1;
        if (L <= m) update(L, R, Lson);
        if (m < R) update(L, R, Rson);
        pushup(o);
        return;
    }
    if (L <= l && r <= R)
    {
        ++t[o], --v[o];
        return;
    }
    pushdown(o);
    int m = l + r >> 1;
    if (L <= m) update(L, R, Lson);
    if (m < R) update(L, R, Rson);
    pushup(o);
}
}; // namespace SegmentTree

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        SegmentTree::build(1, n, 1);
        BIT::init();
        while (q--)
        {
            static char op[10];
            static int l, r;
            scanf("%s%d%d", op, &l, &r);
            if (op[0] == 'a')
                SegmentTree::update(l, r, 1, n, 1);
            else
                printf("%d\n", BIT::query(l, r));
        }
    }
}