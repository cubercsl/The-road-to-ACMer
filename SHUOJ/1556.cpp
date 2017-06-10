#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
bool vis[10];
bool ok;
int maze[10][10];

void dfs(int x, int y)
{
    if (ok)
        return;
    if (x < 0 || y > x)
        return;
    int tmp = maze[x][y];
    if (vis[tmp])
        return;
    vis[tmp] = 1;
    if (x == 9)
    {
        ok = 1;
        return;
    }
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
    vis[tmp] = 0;
}

int main()
{
    int T;
    cin >> T;
    int kase = 0;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        ok = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j <= i; j++)
                cin >> maze[i][j];
        dfs(0, 0);
        cout << "Case " << ++kase << ":" << endl;
        ok ? cout << "Possible" : cout << "Impossible";
        cout << endl;
    }
    return 0;
}
