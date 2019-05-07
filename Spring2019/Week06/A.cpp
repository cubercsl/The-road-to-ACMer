#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 17;

namespace SegmantTree
{
int n;
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
struct Node
{
    int sz;
    ll sum, sum2;
    Node(int sz = 0, ll sum = 0, ll sum2 = 0) : sz(sz), sum(sum), sum2(sum2) {}
    friend Node operator+(const Node& a, const Node& b)
    {
        return Node(a.sz + b.sz,
                    a.sum + b.sum,
                    a.sum2 + b.sum2);
    }
} t[N << 2];
inline void pushup(int o) { t[o] = t[lson] + t[rson]; }
void build(int l = 1, int r = n, int o = 1)
{
    if (l == r)
    {
        t[o].sum = t[o].sum2 = t[o].sz = (l == 1 ? n : 0);
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(o);
}
void insert(int p, int l = 1, int r = n, int o = 1)
{
    if (l == r)
    {
        t[o].sz++;
        t[o].sum += p;
        t[o].sum2 += (ll)p * p;
        return;
    }
    const int m = l + r >> 1;
    if (p <= m)
        insert(p, Lson);
    else
        insert(p, Rson);
    pushup(o);
}
void erase(int p, int l = 1, int r = n, int o = 1)
{
    if (l == r)
    {
        t[o].sz--;
        t[o].sum -= p;
        t[o].sum2 -= (ll)p * p;
        return;
    }
    const int m = l + r >> 1;
    if (p <= m)
        erase(p, Lson);
    else
        erase(p, Rson);
    pushup(o);
}
int query(ll k, int sum = 0, int l = 1, int r = n, int o = 1)
{
    assert(k > 0);
    if (l == r)
    {
        int l0 = 1, r0 = t[o].sz, ans = 0;
        while (l0 <= r0)
        {
            int m0 = l0 + r0 >> 1;
            if ((ll)m0 * (m0 - 1) / 2 * l * l + (ll)m0 * l * sum >= k)
                ans = m0, r0 = m0 - 1;
            else
                l0 = m0 + 1;
        }
        return ans;
    }
    const int m = l + r >> 1;
    ll tmp = (t[rson].sum * t[rson].sum - t[rson].sum2) / 2 + t[rson].sum * sum;
    if (tmp < k)
        return t[rson].sz + query(k - tmp, sum + t[rson].sum, Lson);
    return query(k, sum, Rson);
}
} // namespace SegmantTree

namespace DSU
{
int fa[N], sz[N];
void init(int n)
{
    iota(fa, fa + n, 0);
    fill(sz, sz + n, 1);
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y;
    sz[y] += sz[x];
    sz[x] = 0;
}
bool same(int x, int y) { return find(x) == find(y); }
} // namespace DSU

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        SegmantTree::n = n;
        DSU::init(n);
        int cnt = n;
        long long sum = 0;
        SegmantTree::build();
        while (q--)
        {
            static int p, u, v;
            static long long k;
            scanf("%d", &p);
            if (p == 1)
            {
                scanf("%d%d", &u, &v);
                --u, --v;
                u = DSU::find(u), v = DSU::find(v);
                if (u != v)
                {
                    cnt--;
                    sum -= 1LL * DSU::sz[u] * (DSU::sz[u] - 1) / 2;
                    sum -= 1LL * DSU::sz[v] * (DSU::sz[v] - 1) / 2;
                    SegmantTree::erase(DSU::sz[u]);
                    SegmantTree::erase(DSU::sz[v]);
                    // u -> v
                    DSU::unite(u, v);
                    sum += 1LL * DSU::sz[v] * (DSU::sz[v] - 1) / 2;
                    SegmantTree::insert(DSU::sz[v]);
                }
                sum--;
            }
            else
            {
                scanf("%lld", &k);
                printf("%lld ", max(1LL, (ll)cnt - k));
                printf("%d\n", k - sum > 0 ? cnt + 1 - SegmantTree::query(k - sum) : cnt);
            }
        }
    }
}