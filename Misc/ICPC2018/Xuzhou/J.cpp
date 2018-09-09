#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int maxn = 500 * 500 + 10;
vector<int> G[maxn];
vector<int> sp;
ll dep[maxn], dfn[maxn];
PII dp[21][maxn << 1];
void dfs(int u, int fa)
{
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
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

ll ask(int u, int v)
{
    int d = lca(u, v);
    return dep[u] + dep[v] - dep[d] * 2LL;
}

struct Edge
{
    int from, to, cost;
    Edge(int u = 0, int v = 0, int c = 0) : from(u), to(v), cost(c) {}
    bool operator<(const Edge& rhs) const
    {
        return cost > rhs.cost;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    char c1, c2;
    int x1, x2;
    vector<Edge> edges;
    cin >> n >> m;
    auto getid = [&](int i, int j) {
        return i * m + j + 1;
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c1 >> x1 >> c2 >> x2;
            if (c1 != 'X')
                edges.emplace_back(getid(i, j), getid(i + 1, j), x1);
            if (c2 != 'X')
                edges.emplace_back(getid(i, j), getid(i, j + 1), x2);
        }
    sort(edges.begin(), edges.end());
    vector<int> fa(n * m + 1);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
    for (auto& e : edges)
    {
        int u = e.from, v = e.to, w = e.cost;
        if (find(u) == find(v)) continue;
        fa[find(u)] = find(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    initrmq();
    int q;
    cin >> q;
    while (q--)
    {
        static int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --x2, --y1, --y2;
        cout << ask(getid(x1, y1), getid(x2, y2)) << "\n";
    }
}