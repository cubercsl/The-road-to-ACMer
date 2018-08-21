#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int maxn = 1 << 18;
struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], val[maxn];
    vector<int> G[maxn];
    vector<PII> edges;
    void init(int n)
    {
        this->n = n, memset(son, -1, sizeof(son)), dfs_clock = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v) { G[u].push_back(v), G[v].push_back(u), edges.emplace_back(u, v); }
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
    void update_path(int u, int v)
    {
        int ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(id[top[u]], 1);
            update(id[u] + 1, -1);
            u = fa[top[u]];
        }
        if (u == v) return;
        if (dep[u] > dep[v]) swap(u, v);
        update(id[son[u]], 1);
        update(id[v] + 1, -1);
    }
    // BIT
    int bit[maxn];
    void update(int x, int v)
    {
        for (int i = x; i < maxn; i += i & -i) bit[i] += v;
    }
    ll query(int x)
    {
        ll t = 0;
        for (int i = x; i; i -= i & -i) t += bit[i];
        return t;
    }
    vector<ll> solve()
    {
        vector<ll> w;
        for (int i = 2; i <= n; i++) w.push_back(query(i));
        return w;
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    gao.init(n);
    vector<int> val;
    for (int i = 1, u, v, w; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        gao.add_edge(u, v);
        val.push_back(w);
    }
    gao.dfs(1, 0, 0);
    gao.link(1, 1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
        gao.update_path(u, v);
    }
    sort(val.begin(), val.end(), greater<int>());
    auto w = gao.solve();
    sort(w.begin(), w.end());
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) ans += w[i] * val[i];
    printf("%lld\n", ans);
    return 0;
}