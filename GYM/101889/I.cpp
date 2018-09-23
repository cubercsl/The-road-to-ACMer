#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
array<int, N> G;
struct Edge
{
    int from, to, cost;
    Edge(int u, int v, int w) : from(u), to(v), cost(w) {}
    bool operator<(const Edge& rhs) const
    {
        return cost < rhs.cost;
    }
};

array<int, N> fa;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline bool same(int x, int y) { return find(x) == find(y); }
inline void unite(int x, int y) { fa[find(x)] = find(y); }

struct HLD
{
    int n, dfs_clock;
    int sz[N], top[N], son[N], dep[N], fa[N], id[N], val[N];
    vector<int> G[N];
    vector<pair<pair<int, int>, int>> edges;
    void init(int n)
    {
        this->n = n, memset(son, -1, sizeof(son)), dfs_clock = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v, int w) { G[u].push_back(v), G[v].push_back(u), edges.push_back({{u, v}, w}); }
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
    int a[N];
    int dp[N][30];
    void getval()
    {
        memset(a, 0, sizeof(a));
        for (auto& e : edges)
        {
            int &u = e.first.first, &v = e.first.second;
            int w = e.second;
            if (dep[u] > dep[v]) swap(u, v);
            a[id[v]] = w;
        }
        for (int i = 1; i <= n; i++) dp[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++) dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
    int query(int u, int v)
    {
        int ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret = max(ret, rmq(id[top[u]], id[u]));
            u = fa[top[u]];
        }
        if (u == v) return ret;
        if (dep[u] > dep[v]) swap(u, v);
        ret = max(ret, rmq(id[son[u]], id[v]));
        return ret;
    }
    int rmq(int l, int r)
    {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
} T;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Edge> edges;
    map<pair<int, int>, int> dic;
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (u > v) swap(u, v);
        edges.emplace_back(u, v, w);
        dic[{u, v}] = w;
    }
    sort(edges.begin(), edges.end());
    iota(fa.begin(), fa.end(), 0);
    set<pair<int, int>> tree;
    T.init(n);
    int ans = 0, cnt = 0;
    for (auto& e : edges)
    {
        if (same(e.from, e.to)) continue;
        unite(e.from, e.to);
        ans += e.cost;
        T.add_edge(e.from, e.to, e.cost);
        tree.insert({e.from, e.to});
        if (++cnt == n - 1) break;
    }
    T.dfs(1, 1, 0);
    T.link(1, 1);
    T.getval();
    int q;
    scanf("%d", &q);
    for (int i = 0, u, v; i < q; i++)
    {
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        if (tree.count({u, v}))
            printf("%d\n", ans);
        else
            printf("%d\n", ans + dic[{u, v}] - T.query(u, v));
    }
}