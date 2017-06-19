// FatMouse and Cheese, HDU1078

/*Sample Input
3 1
1 2 5
10 11 6
12 12 7
-1 -1
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
int n, k;
int maze[maxn][maxn];
int dp[maxn][maxn];
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

bool judge(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;
    return true;
}

int dfs(int x, int y)
{
    int MAX = 0;
    if (dp[x][y])
        return 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < 4; j++)
        {
            int nx = x + i * tx[j];
            int ny = y + i * ty[j];
            if (!judge(nx, ny))
                continue;
            if (maze[nx][ny] > maze[x][y])
                MAX = max(MAX, dfs(nx, ny));
        }
    dp[x][y] = MAX + maze[x][y];
    return dp[x][y];
}

int main()
{
    while (cin >> n >> k, n > 0 && k > 0)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> maze[i][j];
        cout << dfs(0, 0) << endl;
    }
    return 0;
}
