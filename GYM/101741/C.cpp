#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct HLD
{
    int n, dfn;
    int bit[maxn];
    int sz[maxn], top[maxn], son[maxn], dep[maxn], par[maxn], id[maxn], rk[maxn];
    vector<int> G[maxn];
    void init(int n)
    {
        this->n = n;
        memset(son, -1, sizeof(son));
        memset(bit, 0, sizeof(bit));
        dfn = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void addedge(int u, int v)
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void dfs(int u, int fa, int d)
    {
        dep[u] = d;
        par[u] = fa;
        sz[u] = 1;
        for (auto& v : G[u])
        {
            if (v == fa) continue;
            dfs(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
        }
    }
    void link(int u, int t)
    {
        top[u] = t;
        id[u] = ++dfn;
        rk[dfn] = u;
        if (son[u] == -1) return;
        link(son[u], t);
        for (auto& v : G[u])
            if (v != son[u] && v != par[u])
                link(v, v);
    }
    int lca(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = par[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        return u;
    }
    void update_p(int u)
    {
        update(id[u]);
    }
    int query_path(int u, int v)
    {
        int ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += query(id[top[u]], id[u]);
            u = par[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        ret += query(id[u], id[v]);
        return ret;
    }
    void update(int u)
    {
        for (int i = u; i <= n; i += i & (-i))
            bit[i]++;
    }
    int query(int u, int v)
    {
        int ret = 0;
        for (int i = u - 1; i > 0; i -= i & (-i)) ret -= bit[i];
        for (int i = v; i > 0; i -= i & (-i)) ret += bit[i];
        return ret;
    }

} hld;
struct Node
{
    int l, r, lca, dep;
    bool operator<(const Node& A) const
    {
        return dep > A.dep;
    }
};
vector<Node> a;
int main()
{
    int n, m;
    scanf("%d", &n);
    hld.init(n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        hld.addedge(u, v);
    }
    hld.dfs(1, 1, 0);
    hld.link(1, 1);
    scanf("%d", &m);
    for (int i = 0, u, v, lca; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        lca = hld.lca(u, v);
        a.push_back({u, v, lca, hld.dep[lca]});
    }
    sort(a.begin(), a.end());
    vector<int> p;
    for (auto& u : a)
    {
        if (hld.query_path(u.l, u.r)) continue;
        hld.update_p(u.lca);
        p.push_back(u.lca);
    }
    int ans = p.size();
    printf("%d\n", ans);
    for (auto& v : p) printf("%d ", v);
    puts("");
}