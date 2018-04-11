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

const int maxn = 1 << 15;
struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], val[maxn];
    vector<int> G[maxn];
    void init(int n)
    {
        this->n = n, clr(son, -1), dfs_clock = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v) { G[u].pb(v), G[v].pb(u); }
    void dfs(int u, int p, int d)
    {
        dep[u] = d, fa[u] = p, sz[u] = 1;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (v == p) continue;
            dfs(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
        }
    }
    void link(int u, int t)
    {
        top[u] = t, id[u] = ++dfs_clock;
        if (son[u] == -1) return;
        link(son[u], t);
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (v != son[u] && v != fa[u]) link(v, v);
        }
    }
    void getval()
    {
        for (int i = 1; i <= n; i++) scanf("%d", &val[id[i]]);
    }
    void update(int u, int v) { update(id[u], v, 1, n); }
    int query_max(int u, int v)
    {
        int ret = -INF;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret = max(ret, query_max(id[top[u]], id[u], 1, n));
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        ret = max(ret, query_max(id[u], id[v], 1, n));
        return ret;
    }
    int query_sum(int u, int v)
    {
        int ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += query_sum(id[top[u]], id[u], 1, n);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        ret += query_sum(id[u], id[v], 1, n);
        return ret;
    }
// Segment Tree
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, mid, lson
#define Rson mid + 1, r, rson
    int sumv[maxn << 2], maxv[maxn << 2];
    inline void pushup(int rt)
    {
        sumv[rt] = sumv[lson] + sumv[rson];
        maxv[rt] = max(maxv[lson], maxv[rson]);
    }
    void build(int l, int r, int rt = 1)
    {
        if (l == r)
        {
            sumv[rt] = maxv[rt] = val[l];
            return;
        }
        int mid = l + r >> 1;
        build(Lson), build(Rson);
        pushup(rt);
    }
    void update(int p, int v, int l, int r, int rt = 1)
    {
        if (l == r)
        {
            sumv[rt] = maxv[rt] = v;
            return;
        }
        int mid = l + r >> 1;
        if (p <= mid)
            update(p, v, Lson);
        else
            update(p, v, Rson);
        pushup(rt);
    }
    int query_max(int L, int R, int l, int r, int rt = 1)
    {
        if (L <= l && r <= R) return maxv[rt];
        int mid = l + r >> 1, ret = -INF;
        if (L <= mid) ret = max(ret, query_max(L, R, Lson));
        if (mid < R) ret = max(ret, query_max(L, R, Rson));
        return ret;
    }
    int query_sum(int L, int R, int l, int r, int rt = 1)
    {
        if (L <= l && r <= R) return sumv[rt];
        int mid = l + r >> 1, ret = 0;
        if (L <= mid) ret += query_sum(L, R, Lson);
        if (mid < R) ret += query_sum(L, R, Rson);
        return ret;
    }
} T;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    T.init(n);
    for (int i = 1; i < n; i++)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
        T.add_edge(u, v);
    }
    T.dfs(1, 1, 1);
    T.link(1, 1);
    T.getval();
    T.build(1, n);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        static char op[10];
        static int u, v;
        scanf("%s%d%d", op, &u, &v);
        if (!strcmp(op, "CHANGE")) T.update(u, v);
        if (!strcmp(op, "QMAX")) printf("%d\n", T.query_max(u, v));
        if (!strcmp(op, "QSUM")) printf("%d\n", T.query_sum(u, v));
    }
    return 0;
}