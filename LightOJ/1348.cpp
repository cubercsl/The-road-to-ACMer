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

const int maxn = 1 << 17;
struct HLD
{
    int n, dfs_clock;
    vector<int> G[maxn];
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], val[maxn];
    void init(int n)
    {
        this->n = n, clr(son, -1), dfs_clock = 0;
        for (int i = 0; i < n; i++) G[i].clear();
    }
    void add_edges(int u, int v) { G[u].pb(v), G[v].pb(u); }
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
        for (int i = 0; i < n; i++) update(id[i], val[i]);
    }
    void update_point(int x, int y)
    {
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
        if (dep[u] > dep[v]) swap(u, v);
        ret += query(id[u], id[v]);
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
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        gao.init(n);
        for (int i = 0; i < n; i++) scanf("%d", &gao.val[i]);
        for (int i = 1; i < n; i++)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            gao.add_edges(u, v);
        }
        gao.dfs(0, -1, 1);
        gao.link(0, 0);
        gao.getval();
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", ++kase);
        while (q--)
        {
            static int op, a, b;
            scanf("%d%d%d", &op, &a, &b);
            if (op == 0) printf("%d\n", gao.query_path(a, b));
            if (op == 1) gao.update_point(a, b);
        }
    }
    return 0;
}
