#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int maxn = 1 << 17;
const ull mask = 0xffffffffffffffff;

struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn];
    ull ref[maxn];
    vector<int> G[maxn];
    void init(int n)
    {
        this->n = n, memset(son, -1, sizeof(son)), dfs_clock = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v) { G[u].push_back(v), G[v].push_back(u); }
    void dfs(int u, int p, int d)
    {
        dep[u] = d, fa[u] = p, sz[u] = 1;
        for (auto& v : G[u])
        {
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
        for (auto& v : G[u])
            if (v != son[u] && v != fa[u]) link(v, v);
    }

    void update_path(int u, int v, int op, ull val)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(id[top[u]], id[u], op, val, 1, n, 1);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        update(id[u], id[v], op, val, 1, n, 1);
    }

    ull query_path(int u, int v)
    {
        ull ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += query(id[top[u]], id[u], 1, n, 1);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        ret += query(id[u], id[v], 1, n, 1);
        return ret;
    }
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
#define lm (m - (m >> 1))
#define rm (m >> 1)
    ull sum[maxn << 2], addv[maxn << 2], mulv[maxn << 2];
    inline void pushup(int o) { sum[o] = sum[lson] + sum[rson]; }
    inline void pushdown(int o, int m)
    {
        if (addv[o] != 0 || mulv[o] != 1)
        {
            addv[lson] = (mulv[o] * addv[lson] + addv[o]);
            addv[rson] = (mulv[o] * addv[rson] + addv[o]);
            mulv[lson] = mulv[lson] * mulv[o];
            mulv[rson] = mulv[rson] * mulv[o];
            sum[lson] = mulv[o] * sum[lson] + addv[o] * lm;
            sum[rson] = mulv[o] * sum[rson] + addv[o] * rm;
            addv[o] = 0;
            mulv[o] = 1;
        }
    }
    void build(int l, int r, int o)
    {
        addv[o] = 0, mulv[o] = 1;
        sum[o] = 0;
        if (l == r) return;
        const int m = l + r >> 1;
        build(Lson);
        build(Rson);
        pushup(o);
    }
    void update(int L, int R, int op, ull v, int l, int r, int o)
    {
        if (L <= l && r <= R)
        {
            if (op == 1)
            {
                addv[o] *= v;
                mulv[o] *= v;
                sum[o] *= v;
            }
            if (op == 2)
            {
                addv[o] += v;
                sum[o] += v * (r - l + 1);
            }
            return;
        }
        const int m = l + r >> 1;
        pushdown(o, r - l + 1);
        if (L <= m) update(L, R, op, v, Lson);
        if (m < R) update(L, R, op, v, Rson);
        pushup(o);
    }
    ull query(int L, int R, int l, int r, int o)
    {
        if (L <= l && r <= R) return sum[o];
        pushdown(o, r - l + 1);
        const int m = l + r >> 1;
        ull ret = 0;
        if (L <= m) ret += query(L, R, Lson);
        if (m < R) ret += query(L, R, Rson);
        return ret;
    }
} gao;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        gao.init(n);
        for (int i = 2, x; i <= n; i++)
        {
            scanf("%d", &x);
            gao.add_edge(x, i);
        }
        gao.dfs(1, 1, 0);
        gao.link(1, 1);
        gao.build(1, n, 1);
        int m;
        scanf("%d", &m);
        while (m--)
        {
            static int op, u, v;
            static ull x;
            scanf("%d%d%d", &op, &u, &v);
            if (op == 1 || op == 2)
            {
                scanf("%llu", &x);
                gao.update_path(u, v, op, x);
            }
            if (op == 3)
            {
                gao.update_path(u, v, 1, mask);
                gao.update_path(u, v, 2, mask);
            }
            if (op == 4)
            {
                printf("%llu\n", gao.query_path(u, v));
            }
        }
    }
}