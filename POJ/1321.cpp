// 棋盘问题 POJ1321

/*Sample Input
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
*/

#include <iostream>
#include <cstring>
using namespace std;

bool m[8][8];
int n, k, cnt;
bool vis[8][8];

void dfs(int x, int y, int dep)
{
    if (!m[x][y])
        return;
    for (int i = 0; i < n; i++)
        if (vis[x][i] || vis[i][y])
            return;
    // 判断目前状态是否符合要求，不符合则回溯
    if (dep == k)
    {
        cnt++;
        return;
    }
    vis[x][y] = 1;
    // 符合要求做访问标记，进行深搜
    for (int i = x + 1; i < n; i++)
        for (int j = 0; j < n; j++)
            dfs(i, j, dep + 1);
    vis[x][y] = 0;
}

int main()
{
    while (cin >> n >> k)
    {
        if (n == -1 && k == -1)
            break;
        cnt = 0;
        memset(m, 0, sizeof(m));

        char s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> s;
                if (s == '#')
                    m[i][j] = 1;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                memset(vis, 0, sizeof(vis));
                dfs(i, j, 1);
            }
        cout << cnt << endl;
    }
    return 0;
}
