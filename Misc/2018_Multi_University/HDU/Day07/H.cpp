#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1 << 17;
vector<pair<int, int>> G[N];
int fa[N];
struct Edge
{
    int u, v, w;
    int id;
    bool operator<(const Edge& rhs) const
    {
        return w < rhs.w;
    }
};
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v) return;
    fa[v] = u;
}
bool same(int u, int v) { return find(u) == find(v); }

#define X first
#define Y second

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
    void add_edge(int u, int v, int w) { G[u].push_back(v), G[v].push_back(u), edges.push_back(make_pair(make_pair(u, v), w)); }
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
    void getval(int x)
    {
        memset(sumv, 0, sizeof(sumv));
        for (int i = 0; i < edges.size(); i++)
        {
            if (i == x - 1) continue;
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
    ll sumv[N << 2];
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
} gao;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) G[i].clear(), fa[i] = i;
        vector<Edge> e(n);
        int id = 0;
        for (auto& t : e) scanf("%d%d%d", &t.u, &t.v, &t.w), t.id = ++id;
        sort(e.begin(), e.end());
        int u, v, w;
        for (auto& t : e)
        {
            if (same(t.u, t.v))
            {
                u = t.u, v = t.v, w = t.w;
                id = t.id;
                continue;
            }
            unite(t.u, t.v);
        }
        sort(e.begin(), e.end(), [&](const Edge& a, const Edge& b) {
            return a.id < b.id;
        });
        gao.init(n);
        for (auto& t : e)
        {
            if (t.id == id)
                gao.add_edge(0, 0, 0);
            else
                gao.add_edge(t.u, t.v, t.w);
        }
        gao.dfs(1, -1, 0);
        gao.link(1, 0);
        gao.getval(id);
        while (q--)
        {
            static int op, x, y;
            scanf("%d%d%d", &op, &x, &y);
            if (op == 0)
            {
                if (x == id)
                    w = y;
                else
                    gao.update_path(x, y);
            }
            else
            {
                long long ans = gao.query_sum(x, y);
                long long tmp1 = gao.query_sum(x, u) + gao.query_sum(v, y) + w;
                long long tmp2 = gao.query_sum(x, v) + gao.query_sum(u, y) + w;
                ans = min({ans, tmp1, tmp2});
                printf("%lld\n", ans);
            }
        }
    }
}