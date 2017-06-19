#include <bits/stdc++.h>
using namespace std;

char maze[102][102];
bool vis[102][102];
int n, m;

void dfs(int x, int y, int id)
{
    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || maze[x][y] != '@')
        return;
    vis[x][y] = 1;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            dfs(x + i, y + j, id);
}

int main()
{
    while (cin >> n >> m, n && m)
    {
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        memset (vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] == '@' && vis[i][j] == 0)
                    dfs(i, j, cnt++);
        cout << cnt << endl;
    }
    return 0;
}
