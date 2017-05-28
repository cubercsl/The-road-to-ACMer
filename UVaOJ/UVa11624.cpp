// Fire!, UVa11624

/*Sample Input
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
const int maxn = 1010;
char maze[maxn][maxn];
int vis[maxn][maxn];
int fire[maxn][maxn];
queue<pair<int, int> > q;

const int tx[] = {-1, 0, 1, 0};
const int ty[] = {0, -1, 0, 1};

void bfs_fire()
{
    while (!q.empty())
        q.pop();
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (maze[i][j] == 'F')
            {
                fire[i][j] = 1;
                q.push(make_pair(i, j));
            }
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                // 地图范围外的坐标
                continue;
            if (fire[nx][ny])
                // 已经着火的坐标
                continue;
            if (maze[nx][ny] == '#')
                // 墙体
                continue;
            fire[nx][ny] = fire[x][y] + 1;
            // 火烧到对应坐标所需要的时间
            q.push(make_pair(nx, ny));
        }
    }
}

int bfs(int jx, int jy)
{
    while (!q.empty())
        q.pop();
    vis[jx][jy] = 1;
    q.push(make_pair(jx, jy));
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        if (x == 0 || y == 0 || x == R - 1 || y == C - 1)
            // 到达边界成功逃脱
            return vis[x][y];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (vis[nx][ny])
                // 访问过的坐标
                continue;
            if (maze[nx][ny] == '#')
                // 墙体
                continue;
            if (fire[nx][ny] && vis[x][y] + 1 >= fire[nx][ny])
                // 着火前无法通过的坐标
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int jx, jy;
        memset(vis, 0, sizeof(vis));
        memset(fire, 0, sizeof(vis));
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'J')
                    jx = i, jy = j;
            }
        bfs_fire();
        int ans = bfs(jx, jy);
        if (ans)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
