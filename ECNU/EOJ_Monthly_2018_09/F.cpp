#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int maxn = 1 << 18;
vector<int> G[maxn], sp;
int dep[maxn], dfn[maxn];
PII dp[21][maxn << 1];
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
    sp.clear();
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
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

int fa[maxn], cnt[maxn];

void go(int u)
{
    for (auto& v : G[u])
    {
        go(v);
        cnt[u] += cnt[v];
    }
}

int DP[maxn];

int gogo(int u, int k)
{
    if (~DP[u]) return DP[u];
    DP[u] = 0;
    if (fa[u] == 0) return DP[u];
    if (cnt[u] >= k) return DP[u] = gogo(fa[u], k) + 1;
    return DP[u];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        G[fa[i]].push_back(i);
    }
    dfs(1, 0);
    initrmq();
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        cnt[u]++, cnt[v]++;
        cnt[lca(u, v)] -= 2;
    }
    go(1);
    int k;
    scanf("%d", &k);
    int ans = 0;
    memset(DP, -1, sizeof(DP));
    for (int i = 1; i <= n; i++) ans = max(gogo(i, k), ans);
    printf("%d\n", ans);
}