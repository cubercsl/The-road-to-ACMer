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
int a[maxn];

struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], val[maxn];
    vector<int> G[maxn];
    void init(int n)
    {
        this->n = n, clr(son, -1), clr(bit, 0), dfs_clock = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v) { G[u].pb(v), G[v].pb(u); }
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
        for (int i = 1; i <= n; i++) update(id[i], a[i]), update(id[i] + 1, -a[i]);
    }
    int update_path(int u, int v, int w)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(id[top[u]], w), update(id[u] + 1, -w);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        update(id[u], w), update(id[v] + 1, -w);
    }
    int query_point(int x) { return query(id[x]); }
    // BIT
    int bit[maxn];
    void update(int x, int v)
    {
        for (int i = x; i < maxn; i += i & -i) bit[i] += v;
    }
    int query(int x)
    {
        int sum = 0;
        for (int i = x; i; i -= i & -i) sum += bit[i];
        return sum;
    }

} T;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, p;
    while (~scanf("%d%d%d", &n, &m, &p))
    {
        T.init(n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 0; i < m; i++)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            T.add_edge(u, v);
        }
        T.dfs(1, 1, 1);
        T.link(1, 1);
        T.getval();
        while (p--)
        {
            static char op;
            static int u, v, w;
            scanf(" %c", &op);
            if (op == 'I')
            {
                scanf("%d%d%d", &u, &v, &w);
                T.update_path(u, v, w);
            }
            else if (op == 'D')
            {
                scanf("%d%d%d", &u, &v, &w);
                T.update_path(u, v, -w);
            }
            else
            {
                scanf("%d", &u);
                printf("%d\n", T.query_point(u));
            }
        }
    }
    return 0;
}