// Dungeon Master, POJ2251

/*Sample Input
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char map[35][35][35];
bool vis[35][35][35];
int tx[6] = {-1, 0, 1, 0, 0, 0};
int ty[6] = {0, -1, 0, 1, 0, 0};
int tz[6] = {0, 0, 0, 0, 1, -1};
int L, R, C, sx, sy, sz, ex, ey, ez;

struct node
{
    int x, y, z, step;
};

bool check(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0 || x >= R || y >= C || z >= L)
        return false;
    if (map[z][x][y] == '#')
        return false;
    if (vis[z][x][y])
        return false;
    return true;
}

int bfs()
{
    node temp, next;
    queue<node> q;
    temp.x = sx, temp.y = sy, temp.z = sz;
    temp.step = 0;
    vis[sz][sx][sy] = 1;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp.x == ex && temp.y == ey && temp.z == ez)
            return temp.step;
        for (int i = 0; i < 6; i++)
        {
            next.x = temp.x + tx[i];
            next.y = temp.y + ty[i];
            next.z = temp.z + tz[i];
            if (!check(next.x, next.y, next.z))
                continue;
            vis[next.z][next.x][next.y] = 1;
            next.step = temp.step + 1;
            q.push(next);
        }
    }
    return 0;
}

int main()
{
    while (scanf("%d%d%d", &L, &R, &C), L + R + C)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < L; i++)
            for (int j = 0; j < R; j++)
            {
                scanf("%s", map[i][j]);
                for (int k = 0; k < C; k++)
                    if (map[i][j][k] == 'S')
                        sx = j, sy = k, sz = i;
                    else if (map[i][j][k] == 'E')
                        ex = j, ey = k, ez = i;
            }
        int ans = bfs();
        if (ans)
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}
