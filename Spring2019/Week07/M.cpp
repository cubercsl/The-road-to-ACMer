#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 9;
int a[N][N];

struct Edge
{
    int from, to;
    int cost;
    bool operator<(const Edge& rhs) const
    {
        return cost < rhs.cost;
    }
    Edge(int u, int v, int w) : from(u), to(v), cost(w) {}
};

namespace DSU
{
const int N = 1 << 18;
int fa[N];
void init() { iota(fa, fa + N, 0); }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same(int x, int y) { return find(x) == find(y); }
void unite(int x, int y) { fa[find(x)] = find(y); }
} // namespace DSU
typedef pair<int, int> PII;
typedef long long ll;
struct HLD
{
#define X first
#define Y second
    const static int N = 1 << 18;
    int n, dfs_clock;
    int sz[N], top[N], son[N], dep[N], fa[N], id[N], val[N];
    vector<int> G[N];
    vector<pair<PII, int> > edges;
    void init(int n)
    {
        this->n = n, memset(son, -1, sizeof(son)), dfs_clock = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v, int w) { G[u].push_back(v), G[v].push_back(u), edges.push_back(make_pair(make_pair(u, v), w)); }
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
            int &u = e.X.X, &v = e.X.Y;
            int w = e.Y;
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
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    auto id = [&](int x, int y) { return x * m + y + 1; };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n) edges.emplace_back(id(i, j), id(i + 1, j), max(a[i][j], a[i + 1][j]));
            if (j + 1 < m) edges.emplace_back(id(i, j), id(i, j + 1), max(a[i][j], a[i][j + 1]));
        }
    DSU::init();
    T.init(n * m + 10);
    sort(edges.begin(), edges.end());
    for (auto [u, v, w] : edges)
    {
        if (DSU::same(u, v)) continue;
        T.add_edge(u, v, w);
        DSU::unite(u, v);
    }
    T.dfs(1, 1, 1);
    T.link(1, 1);
    T.getval();
    for (int i = 0, x1, y1, x2, y2; i < q; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1, --y1, --x2, --y2;
        int u = id(x1, y1);
        int v = id(x2, y2);
        if (u == v)
            printf("%d\n", a[x1][y1]);
        else
            printf("%d\n", T.query(u, v));
    }
}