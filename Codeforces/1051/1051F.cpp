#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1 << 17;
struct Edge
{
    int from, to, cost;
    Edge(int u, int v, int c) : from(u), to(v), cost(c) {}
    bool operator<(const Edge& rhs) const
    {
        return cost < rhs.cost;
    }
};

vector<pair<int, int> > G[maxn];
vector<int> sp;
ll dep[maxn];
int dfn[maxn];
pair<int, int> dp[21][maxn << 1];

void dfs(int u, int fa)
{
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& e : G[u])
    {
        int v = e.first;
        int w = e.second;
        if (v == fa) continue;
        dep[v] = dep[u] + w;
        dfs(v, u);
        sp.push_back(u);
    }
}
void initrmq()
{
    int n = sp.size();
    for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
}

ll ask(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)] * 2LL; }

int fa[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline bool same(int x, int y) { return find(x) == find(y); }
inline void unite(int x, int y) { fa[find(x)] = find(y); }

typedef pair<ll, int> E;
vector<E> GG[maxn];
inline void addedge(int u, int v, ll w)
{
    GG[u].emplace_back(w, v);
    GG[v].emplace_back(w, u);
}

ll dis[50][maxn];
bool vis[maxn];
void Dijkstra(int s, int id)
{
    memset(vis, 0, sizeof(vis));
    memset(dis[id], 0x3f, sizeof(dis[id]));
    dis[id][s] = 0;
    priority_queue<E, vector<E>, greater<E> > q;
    q.push({dis[id][s], s});
    while (!q.empty())
    {
        E t = q.top();
        int x = t.second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < GG[x].size(); i++)
        {
            int y = GG[x][i].second;
            ll w = GG[x][i].first;
            if (!vis[y] && dis[id][y] > dis[id][x] + w)
            {
                dis[id][y] = dis[id][x] + w;
                q.push({dis[id][y], y});
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Edge> edges;
    for (int i = 0, u, v, c; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        edges.emplace_back(u, v, c);
    }
    iota(fa, fa + maxn, 0);
    sort(edges.begin(), edges.end());
    vector<int> key;
    for (auto& e : edges)
    {
        int u = e.from, v = e.to, w = e.cost;
        addedge(u, v, w);
        if (same(u, v))
        {
            key.push_back(u);
            key.push_back(v);
            continue;
        }
        unite(u, v);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    dfs(1, 0);
    initrmq();
    sort(key.begin(), key.end());
    key.erase(unique(key.begin(), key.end()), key.end());
    for (int i = 0; i < key.size(); i++) Dijkstra(key[i], i);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
        ll ans = ask(u, v);
        for (int i = 0; i < key.size(); i++)
        {
            ll tmp = dis[i][u] + dis[i][v];
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans);
    }
}