#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 11;
char maze[N][N];

const int maxn = 1 << 20;
vector<pair<int, int>> G[maxn];
vector<int> sp;
int dep[maxn], dfn[maxn];
pair<int, int> dp[21][maxn << 1];

void dfs(int u, int fa)
{
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& [v, w] : G[u])
    {
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

int ask(int x, int y)
{
    // cerr << x << ' ' << y << endl;
    int ans = dep[x] + dep[y] - 2 * dep[lca(x, y)];
    // cerr << ans << endl;
    return ans;
}

void addedge(int u, int v, int w)
{
    // cerr << u << ' ' << v << ' ' << w << endl;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
}

map<pair<int, int>, int> dic;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int h, w;
    scanf("%d%d", &h, &w);
    getchar();
    for (int i = 0; i <= h; i++) fgets(maze[i], 1 << 11, stdin);
    int m;
    scanf("%d", &m);
    int sz = 0;
    vector<pair<int, int>> vec;
    for (int i = 0, x, y; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        vec.emplace_back(x, y);
    }
    for (int x = 1; x <= h; x++)
        for (int y = 1; y <= w; y++)
        {
            if (x + 1 <= h && maze[x][y * 2 - 1] != '_') addedge((x - 1) * w + y, x * w + y, 1);
            if (y + 1 <= w && maze[x][y * 2] != '|') addedge((x - 1) * w + y, (x - 1) * w + y + 1, 1);
        }
    dfs(1, 0);
    initrmq();
    long long ans = 0;
    auto id = [&](const pair<int, int>& p) { return (p.first - 1) * w + p.second; };
    for (int i = 0; i < m - 1; i++) ans += ask(id(vec[i]), id(vec[i + 1]));
    printf("%lld\n", ans);
}