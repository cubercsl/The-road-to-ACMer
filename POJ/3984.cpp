// 迷宫问题, POJ3984

/*Sample Input
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int tx[] = {-1, 0, 1, 0};
const int ty[] = {0, -1, 0, 1};

bool maze[5][5];
bool vis[5][5];

struct node
{
    int x, y;
};

node temp, next, pre[5][5];

bool judge(int x, int y)
{
    if (x < 0 || y < 0 || x >= 5 || y >= 5)
        return false;
    if (vis[x][y] || maze[x][y])
        return false;
    return true;
}

void print(int x, int y)
{
    // 若不是起始点,则输出上一个结点的坐标
    if (x == 0 && y == 0)
        return;
    else
        print(pre[x][y].x, pre[x][y].y);
    printf("(%d, %d)\n", pre[x][y].x, pre[x][y].y);
}

void bfs()
{
    temp.x = temp.y = 0;
    queue<node> q;
    while (!q.empty())
        q.pop();
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp.x == 4 && temp.y == 4)
        {
            print(4, 4);
            printf("(4, 4)\n");
            return;
        }
        vis[temp.x][temp.y] = 1;
        for (int i = 0; i < 4; i++)
        {
            next.x = temp.x + tx[i], next.y = temp.y + ty[i];
            if (!judge(next.x, next.y))
                continue;
            pre[next.x][next.y].x = temp.x;
            pre[next.x][next.y].y = temp.y;
            // 记录上一个结点的位置。
            q.push(next);
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> maze[i][j];
    bfs();
    return 0;
}
