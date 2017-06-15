// Curling 2.0, POJ3009

/*Sample Input
2 1
3 2
6 6
1 0 0 2 1 0
1 1 0 0 0 0
0 0 0 0 0 3
0 0 0 0 0 0
1 0 0 0 0 1
0 1 1 1 1 1
6 1
1 1 2 1 1 3
6 1
1 0 2 1 1 3
12 1
2 0 1 1 1 1 1 1 1 1 1 3
13 1
2 0 1 1 1 1 1 1 1 1 1 1 3
0 0
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int w, h, ans;
int maze[21][21];
int sx, sy;
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

void dfs(int x, int y, int dir, int dep)
{
    if (dep > 10) // 递归边界
        return;
    int cnt = 0;
    while (maze[x][y] != 1)
    {
        x += tx[dir], y += ty[dir];
        if (x < 0 || y < 0 || x >= h || y >= w) // 出界
            return;
        if (maze[x][y] == 3)
        {
            ans = min(dep, ans); // 到达
            return;
        }
        cnt++;
    }
    if (cnt == 1)
        return; // 立即撞击的情况需要排除
    maze[x][y] = 0; // 撞击之后砖块消失
    for (int i = 0; i < 4; i++)
        dfs(x - tx[dir], y - ty[dir], i, dep + 1);
    maze[x][y] = 1; // 回溯时将砖块放回
}

int main()
{
    while (cin >> w >> h, w && h)
    {
        ans = INF;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 2)
                    sx = i, sy = j;
            }
        for (int i = 0; i < 4; i++)
            dfs(sx, sy, i, 1);
        if (ans != INF)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
