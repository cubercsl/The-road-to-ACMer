#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
namespace Segment_Tree
{
typedef long long type_t;
const int N = 1 << 19;
type_t minv[N << 2], lazy[N << 2];
type_t val[N];
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
inline void pushup(int o)
{
    minv[o] = min(minv[lson], minv[rson]);
}
inline void pushdown(int o)
{
    if (!lazy[o]) return;
    lazy[lson] += lazy[o];
    lazy[rson] += lazy[o];
    minv[lson] += lazy[o];
    minv[rson] += lazy[o];
    lazy[o] = 0;
}
void build(int l = 1, int r = N, int o = 1)
{
    if (l == r)
    {
        minv[o] = val[l];
        return;
    }
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(o);
}
void update(int L, int R, type_t v, int l = 1, int r = N, int o = 1)
{
    if (L <= l && r <= R)
    {
        lazy[o] += v;
        minv[o] += v;
        return;
    }
    pushdown(o);
    const int m = l + r >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(o);
}
type_t query(int L, int R, int l = 1, int r = N, int o = 1)
{
    if (L <= l && r <= R) return minv[o];
    pushdown(o);
    const int m = l + r >> 1;
    type_t ret = 1e18;
    if (L <= m) ret = min(ret, query(L, R, Lson));
    if (m < R) ret = min(ret, query(L, R, Rson));
    return ret;
}
#undef lson
#undef rson
#undef Lson
#undef Rson
}; // namespace Segment_Tree

const int N = 1 << 19;
vector<int> G[N];
int w[N];
vector<int> qid[N];
vector<pair<int, int>> query;
vector<ll> ans;
int in[N], out[N];
int dfs_clock;
void dfs(int u, ll d)
{
    in[u] = ++dfs_clock;
    assert(u == in[u]);
    for (auto& v : G[u])
        dfs(v, d + w[v]);
    if (!G[u].size()) Segment_Tree::val[u] = d;
    out[u] = dfs_clock;
}
void go(int u, ll d)
{
    for (auto& id : qid[u])
        ans[id] = Segment_Tree::query(query[id].first, query[id].second) + d;
    for (auto& v : G[u])
    {
        Segment_Tree::update(in[v], out[v], -w[v] * 2);
        go(v, d + w[v]);
        Segment_Tree::update(in[v], out[v], w[v] * 2);
    }
}

int main()
{
    memset(Segment_Tree::val, 0x3f, sizeof(Segment_Tree::val));
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2, p, v; i <= n; i++)
    {
        scanf("%d%d", &p, &v);
        G[p].push_back(i);
        w[i] = v;
    }
    dfs(1, 0);
    Segment_Tree::build();
    for (int i = 0, v, l, r; i < q; i++)
    {
        scanf("%d%d%d", &v, &l, &r);
        qid[v].push_back(i);
        query.emplace_back(l, r);
        ans.emplace_back();
    }
    go(1, 0);
    for (auto t : ans) printf("%lld\n", t);
}