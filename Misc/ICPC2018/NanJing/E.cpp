#include <bits/stdc++.h>
using namespace std;

const int N = 20;
bool vis[21];
int dp[21][1 << N];
int a[21], b[21];
int n;
int need[21];

bool ok(int x, int state)
{
    if (vis[x]) return false;
    return (state & need[x]) == need[x];
}

int dfs(int t, int now)
{
    if (~dp[t][now]) return dp[t][now];
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (ok(i, now))
        {
            vis[i] = 1;
            ret = max(dfs(t + 1, now | (1 << i)) + (t + 1) * a[i] + b[i], ret);
            vis[i] = 0;
        }
    }
    dp[t][now] = ret;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    ::n = n;
    for (int i = 0, s; i < n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &s);
        for (int j = 0, x; j < s; j++)
        {
            scanf("%d", &x);
            need[i] |= (1 << (x - 1));
        }
    }
    printf("%d\n", dfs(0, 0));
}