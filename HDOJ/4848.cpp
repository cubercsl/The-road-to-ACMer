#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 35;
int n;
int ans;
int G[N][N], d[N];
bool vis[N];

void dfs(int u, int cnt, int cur, int tot)
{
    if (!cnt)
    {
        ans = min(ans, tot);
        return;
    }
    for (int i = 0; i < n; i++)
        if (!vis[i] && cur + G[u][i] > d[i]) return;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || tot + cnt * G[u][i] >= ans) continue;
        vis[i] = 1;
        dfs(i, cnt - 1, cur + G[u][i], tot + cnt * G[u][i]);
        vis[i] = 0;
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        ans = INF;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &G[i][j]);
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n;j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        for (int i = 1; i < n; i++)
            scanf("%d", &d[i]);
        vis[0] = 1;
        dfs(0, n - 1, 0, 0);
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}