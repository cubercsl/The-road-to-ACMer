#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto& v : G[u])
    {
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i);
}

int w[maxn], dp[maxn];

int DFS(int u)
{
    if (~dp[u]) return dp[u];
    dp[u] = w[u];
    for (auto& v : G[u])
        dp[u] = max(dp[u], DFS(v) + w[u]);
    return dp[u];
}

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
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) G[i].clear();
        vector<pair<int, int>> edges;
        for (int i = 0, u, v; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            edges.emplace_back(u, v);
        }
        find_scc(n);
        for (int i = 1; i <= n; i++) G[i].clear();
        for (auto& e : edges)
            if (sccno[e.first] != sccno[e.second])
                G[sccno[e.first]].push_back(sccno[e.second]);
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= n; i++) w[sccno[i]]++;
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 1; i <= scc_cnt; i++) ans = max(ans, DFS(i));
        printf("%d\n", ans);
    }
    return 0;
}