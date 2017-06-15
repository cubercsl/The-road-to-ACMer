// Red and Black, POJ1979

/*Sample Input
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
*/

#include <iostream>
#include <cstring>
using namespace std;

int H, W;
char maze[22][22];
bool vis[22][22];
int X, Y;
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};
int ans;
bool flag;

void dfs(int x, int y)
{
    if (flag)
        return;
    if (x < 0 || y < 0 || x >= H || y >= W || maze[x][y] == '#' || vis[x][y])
        return;
    if (x == X && y == Y)
    {
        flag = 1;
        ans++;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        dfs(x + tx[i], y + ty[i]);
}

int main()
{
    while (cin >> W >> H, W && H)
    {
        ans = 0;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == '@')
                    X = i, Y = j;
            }
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (maze[i][j] != '#')
                {
                    flag = 0;
                    memset(vis, 0, sizeof(vis));
                    dfs(i, j);
                }
        cout << ans << endl;
    }
    return 0;
}
