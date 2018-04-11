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

const int maxn = 1 << 16;
struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], val[maxn];
    vector<int> G[maxn];
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
    void getval()
    {
        clr(maxv, 0);
        for (auto& e : edges)
        {
            int &u = e.X.X, &v = e.X.Y, w = e.Y;
            if (dep[u] > dep[v]) swap(u, v);
            update(id[v], w, 1, n);
        }
    }
    int update(int x, int v)
    {
        int& vv = edges[x - 1].X.Y;
        update(id[vv], v, 1, n);
    }
    int query(int u, int v)
    {
        int ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret = max(ret, query(id[top[u]], id[u], 1, n));
            u = fa[top[u]];
        }
        if (u == v) return ret;
        if (dep[u] > dep[v]) swap(u, v);
        ret = max(ret, query(id[son[u]], id[v], 1, n));
        return ret;
    }
// Segment Tree
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
    int maxv[maxn << 2];
    inline void pushup(int rt) { maxv[rt] = max(maxv[lson], maxv[rson]); }
    void update(int p, int v, int l, int r, int rt = 1)
    {
        if (l == r)
        {
            maxv[rt] = v;
            return;
        }
        int m = l + r >> 1;
        if (p <= m)
            update(p, v, Lson);
        else
            update(p, v, Rson);
        pushup(rt);
    }
    int query(int L, int R, int l, int r, int rt = 1)
    {
        if (L <= l && r <= R) return maxv[rt];
        int m = l + r >> 1, ret = 0;
        if (L <= m) ret = max(ret, query(L, R, Lson));
        if (m < R) ret = max(ret, query(L, R, Rson));
        return ret;
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        gao.init(n);
        for (int i = 1; i <= n; i++)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            gao.add_edge(u, v, w);
        }
        gao.dfs(1, 0, 0);
        gao.link(1, 1);
        gao.getval();
        char op[10];
        while (~scanf("%s", op) && op[0] != 'D')
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            if (op[0] == 'C') gao.update(u, v);
            if (op[0] == 'Q') printf("%d\n", gao.query(u, v));
        }
    }
    return 0;
}