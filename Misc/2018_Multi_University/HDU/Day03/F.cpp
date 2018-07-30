#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int a[N];

vector<int> G[N];
int dp[N][2];

void dfs(int u, int fa)
{
    dp[u][0] = 0, dp[u][1] = a[u];
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] = max({dp[u][0], dp[v][0], dp[v][1]});
        dp[u][1] = max(dp[u][1], dp[v][0] ^ a[u]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) G[i].clear();
        int sum = 0;
        for (int i = 1; i <= n; i++) scanf("%d", a + i), sum ^= a[i];
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 0);
        int ans = max(dp[1][0], dp[1][1]);
        sum ^= ans;
        if (ans > sum) puts("Q");
        if (ans < sum) puts("T");
        if (ans == sum) puts("D");
    }
}