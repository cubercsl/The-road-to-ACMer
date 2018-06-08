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

struct Edge
{
    int from, to, cost;
    bool used;
    bool operator<(const Edge& rhs) const { return cost < rhs.cost; }
};
const int N = 1 << 17;
struct HLD
{
    int n, dfs_clock;
    int sz[N], top[N], son[N], dep[N], fa[N], id[N], val[N];
    vector<int> G[N];
    vector<pair<PII, int> > edges;
    void init(int n)
    {
        this->n = n, clr(son, -1), dfs_clock = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v, int w) { G[u].pb(v), G[v].pb(u), edges.pb(mp(mp(u, v), w)); }
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
    ll a[N];
    ll dp[N][30];
    void getval()
    {
        clr(a, 0);
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
    ll query(int u, int v)
    {
        ll ret = 0;
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
    ll rmq(int l, int r)
    {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
} T;

vector<Edge> edges;

int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same(int x, int y) { return find(x) == find(y); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}

ll Kruskal(int n)
{
    T.init(n);
    int cnt = 0;
    iota(fa, fa + N, 0);
    sort(edges.begin(), edges.end());
    ll sum = 0;
    for (auto& e : edges)
    {
        int u = e.from, v = e.to, w = e.cost;
        if (same(u, v)) continue;
        unite(u, v), e.used = true;
        T.add_edge(u, v, w);
        sum += w;
        if (++cnt == n - 1) break;
    }
    T.dfs(1, 1, 1);
    T.link(1, 1);
    T.getval();
    ll ans = 1e18;
    for (auto& e : edges)
    {
        if (e.used) continue;
        ans = min(ans, sum - T.query(e.from, e.to) + e.cost);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        static int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back({u, v, w, 0});
    }
    printf("%lld\n", Kruskal(n));
    return 0;
}
