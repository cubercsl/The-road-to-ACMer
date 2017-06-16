#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
long long dp[25][25];
bool vis[25][25];
int tx[] = { -2, -1, 1, 2, -2, -1, 1, 2};
int ty[] = { -1, -2, 2, 1, 1, 2, -2, -1};

void init()
{
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + tx[i];
        int ny = y + ty[i];
        if (nx < 0 || ny < 0 || nx > n || ny > m)
            continue;
        vis[nx][ny] = 1;
    }

}

void solve()
{
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        if (vis[0][i])
            continue;
        else
            dp[0][i] = dp[0][i - 1];
    for (int i = 1; i <= n; i++)
        if (vis[i][0])
            continue;
        else
            dp[i][0] = dp[i - 1][0];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (vis[i][j])
                continue;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
}

int main()
{
    cin >> n >> m >> x >> y;
    init();
    solve();
    cout << dp[n][m] << endl;
}
