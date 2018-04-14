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

const int maxn = 1 << 15;
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
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
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
            int v = G[u][i];
            if (v != son[u] && v != fa[u]) link(v, v);
        }
    }
    void getval()
    {
        clr(sumv, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            int &u = edges[i].X.X, &v = edges[i].X.Y;
            int w = edges[i].Y;
            if (dep[u] > dep[v]) swap(u, v);
            update(id[v], w, 1, n);
        }
    }
    void update_path(int p, int w)
    {
        int v = edges[p - 1].X.Y;
        update(id[v], w, 1, n);
    }
    ll query_sum(int u, int v)
    {
        ll ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += query_sum(id[top[u]], id[u], 1, n);
            u = fa[top[u]];
        }
        if (u == v) return ret;
        if (dep[u] > dep[v]) swap(u, v);
        ret += query_sum(id[son[u]], id[v], 1, n);
        return ret;
    }
// Segment Tree
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
    ll sumv[maxn << 2];
    inline void pushup(int rt) { sumv[rt] = sumv[lson] + sumv[rson]; }
    void update(int p, int v, int l, int r, int rt = 1)
    {
        if (l == r)
        {
            sumv[rt] = v;
            return;
        }
        int m = l + r >> 1;
        if (p <= m)
            update(p, v, Lson);
        else
            update(p, v, Rson);
        pushup(rt);
    }
    ll query_sum(int L, int R, int l, int r, int rt = 1)
    {
        if (L <= l && r <= R) return sumv[rt];
        int m = l + r >> 1;
        ll ret = 0;
        if (L <= m) ret += query_sum(L, R, Lson);
        if (m < R) ret += query_sum(L, R, Rson);
        return ret;
    }
} T;

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        T.init(n);
        for (int i = 1; i < n; i++)
        {
            static int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            T.add_edge(u, v, c);
        }
        T.dfs(1, 0, 0);
        T.link(1, 1);
        T.getval();
        while (m--)
        {
            static int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (a == 0)
                T.update_path(b, c);
            else
                printf("%lld\n", T.query_sum(b, c));
        }
    }
}