#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int dp[maxn], deg[maxn];

int dfs(int u, int fa)
{
    if (dp[u] != -1) return dp[u];
    dp[u] = 1;
    for (auto& v : G[u])
    {
        if (v != fa && deg[u] < deg[v])
        {
            dp[u] = max(dp[u], dfs(v, u) + 1);
        }
    }
    return dp[u];
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        deg[u]++, deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    // puts("fuck");
    for (int i = 0; i < n; i++)
        ans = max(ans, dfs(i, -1));
    printf("%d\n", ans);
}