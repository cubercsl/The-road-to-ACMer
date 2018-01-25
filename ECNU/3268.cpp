#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
const char step[] = "ULRD";
char maze[maxn][maxn];
int ans[maxn * maxn];
bool vis[maxn][maxn];
bool flag;
int n, m;
int tx[] = {-1, 0, 0, 1};
int ty[] = {0, -1, 1, 0};

void dfs(int x, int y, int dep)
{
    if (flag)
        return;
    if (x == 0 && y == 0)
    {
        flag = 1;
        for (int i = 0; i < dep; i++)
            cout << step[ans[i]];
        for (int i = 1; i < n; i++)
            cout << "D";
        for (int i = 1; i < m; i++)
            cout << "R";
        for (int i = 1; i < n; i++)
            cout << "U";
        for (int i = 1; i < m; i++)
            cout << "L";
        for (int i = dep - 1; i >= 0; i--)
            cout << step[3 - ans[i]];
        return;
    }
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (vis[x][y] || maze[x][y] == '*')
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        ans[dep] = i;
        dfs(x + tx[i], y + ty[i], dep + 1);
    }
    vis[x][y] = 0;
}

int main()
{
    int sx, sy;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'P')
                sx = i, sy = j;
        }
    dfs(sx, sy, 0);
    cout << endl;
    return 0;
}
