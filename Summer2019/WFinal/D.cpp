#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
int a[maxn];

typedef long long ll;
struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], ref[maxn];
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
        ref[dfs_clock] = u;
        if (son[u] == -1) return;
        link(son[u], t);
        for (auto& v : G[u])
            if (v != son[u] && v != fa[u]) link(v, v);
    }
    void update_path(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(id[top[u]], id[u], 1, n, 1);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        update(id[u], id[v], 1, n, 1);
    }
    ll query_path(int u, int v)
    {
        ll ret = 0;
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
    ll sum[maxn << 2];
    bool ok[maxn << 2];
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
    void pushup(int o)
    {
        sum[o] = sum[lson] + sum[rson];
        ok[o] = (ok[lson] && ok[rson]);
    }
    void build(int l, int r, int o)
    {
        if (l == r)
        {
            sum[o] = a[ref[l]];
            ok[o] = (sum[o] <= 1);
            return;
        }
        const int m = l + r >> 1;
        build(Lson);
        build(Rson);
        pushup(o);
    }
    void update(int L, int R, int l, int r, int o)
    {
        if (ok[o]) return;
        if (l == r)
        {
            sum[o] = (ll)sqrt(sum[o]);
            ok[o] = (sum[o] <= 1);
            return;
        }
        const int m = l + r >> 1;
        if (L <= m) update(L, R, Lson);
        if (m < R) update(L, R, Rson);
        pushup(o);
    }
    ll query(int L, int R, int l, int r, int o)
    {
        if (L <= l && r <= R) return sum[o];
        const int m = l + r >> 1;
        ll ans = 0;
        if (L <= m) ans += query(L, R, Lson);
        if (m < R) ans += query(L, R, Rson);
        return ans;
    }
} gao;

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        gao.init(n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            gao.add_edge(u, v);
        }
        gao.dfs(1, 1, 0);
        gao.link(1, 1);
        gao.build(1, n, 1);
        while (q--)
        {
            static int op, u, v;
            scanf("%d%d%d", &op, &u, &v);
            if (op == 0)
                gao.update_path(u, v);
            else
                printf("%lld\n", gao.query_path(u, v));
        }
    }
}