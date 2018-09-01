#include <bits/stdc++.h>
using namespace std;

constexpr int N = 105;
vector<int> G[N];
// 1 Bob输
int dp[N][N][2];
int cnt[N][N];
int deg[N];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        // dp[i][j][0/1]
        // Bob, Alice
        memset(deg, 0, sizeof(deg));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j][0] = dp[i][j][1] = 0, cnt[i][j] = 0;
        for (int i = 0, x, y; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            G[y].push_back(x);
            deg[x]++;
        }
        int x, y;
        queue<tuple<int, int, int>> q;
        scanf("%d%d", &x, &y);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 1;
                    q.push({i, j, 0});
                    q.push({i, j, 1});
                }
                else if (deg[i] == 0)
                {
                    dp[i][j][0] = 1;
                    q.push({i, j, 0});
                }
            }
        while (!q.empty())
        {
            static int x, y, d;
            auto t = q.front();
            q.pop();
            tie(x, y, d) = t;
            // printf("%d %d %d\n",x,y,d);
            if (d == 0)
            { // Alice走
                for (auto& v : G[y])
                {
                    if (dp[x][v][d ^ 1] == 0)
                    {
                        dp[x][v][d ^ 1] = 1;
                        q.push({x, v, d ^ 1});
                    }
                }
            }
            else
            {
                for (auto& v : G[x])
                {
                    if ((++cnt[v][y] == deg[v]) && (dp[v][y][d ^ 1] == 0))
                    {
                        dp[v][y][d ^ 1] = 1;
                        q.push({v, y, d ^ 1});
                    }
                }
            }
        }
        // printf("%d %d\n",x,y);
        printf("Case #%d: ", ++kase);
        puts(dp[x][y][0] ? "No" : "Yes");
    }
}