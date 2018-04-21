#include <cstdio>
#include <cstring>
#include <vector>
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

const int maxn = 1 << 17;
struct HLD
{
    int n, dfs_clock;
    vector<int> G[maxn];
    vector<pair<PII, int> > edges;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], val[maxn];
    void init(int n)
    {
        this->n = n, clr(son, -1), dfs_clock = 0;
        edges.clear();
        for (int i = 0; i < n; i++) G[i].clear();
    }
    void add_edges(int u, int v, int w) { G[u].pb(v), G[v].pb(u), edges.pb(mp(mp(u, v), w)); }
    void dfs(int u, int p, int d)
    {
        dep[u] = d, fa[u] = p, sz[u] = 1;
        for (int i = 0; i < G[u].size(); i++)
        {
            int& v = G[u][i];
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
            int& v = G[u][i];
            if (v != son[u] && v != fa[u]) link(v, v);
        }
    }
    void getval()
    {
        clr(bit, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            int &u = edges[i].X.X, &v = edges[i].X.Y;
            int w = edges[i].Y;
            if (dep[u] > dep[v]) swap(u, v);
            update(id[v], w);
        }
    }
    void update_point(int x, int y)
    {
        x = edges[x - 1].X.Y;
        int v = y - query(id[x], id[x]);
        update(id[x], v);
    }
    int query_path(int u, int v)
    {
        int ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += query(id[top[u]], id[u]);
            u = fa[top[u]];
        }
        if (u == v) return ret;
        if (dep[u] > dep[v]) swap(u, v);
        ret += query(id[son[u]], id[v]);
        return ret;
    }
    // BIT
    int bit[maxn];
    void update(int x, int v)
    {
        for (int i = x; i < maxn; i += i & -i) bit[i] += v;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
    int query(int x)
    {
        int ret = 0;
        for (int i = x; i; i -= i & -i) ret += bit[i];
        return ret;
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q, s;
    scanf("%d%d%d", &n, &q, &s);
    gao.init(n);
    for (int i = 1; i < n; i++)
    {
        static int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        gao.add_edges(u, v, w);
    }
    gao.dfs(1, 1, 1);
    gao.link(1, 1);
    gao.getval();
    while (q--)
    {
        static int op, u, v;
        scanf("%d", &op);
        if (op == 0)
        {
            scanf("%d", &u);
            printf("%d\n", gao.query_path(s, u));
            s = u;
        }
        else
        {
            scanf("%d%d", &u, &v);
            gao.update_point(u, v);
        }
    }
    return 0;
}