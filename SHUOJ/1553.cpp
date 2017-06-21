#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 102;
int r, c, ans;
int maze[maxn][maxn];
int dp[maxn][maxn];
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= r || x >= c)
        return false;
    return true;
}

int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + tx[i];
        int ny = y + ty[i];
        if (!check(nx, ny))
            continue;
        if (maze[nx][ny] < maze[x][y])
            dp[x][y] = max(dfs(nx, ny) + 1, dp[x][y]);
    }
    return dp[x][y];
}

int main()
{
    cin >> r >> c;
    ans = -INF;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> maze[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ans = max(ans, dfs(i, j));
    cout << ans + 1 << endl;
    return 0;
}
