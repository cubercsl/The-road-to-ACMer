#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
int sx, sy, ex, ey;
int tx[] = {2, 1, -1, -2, 2, 1, -1, -2};
int ty[] = {1, 2, -2, -1, -1, -2, 2, 1};
int vis[9][9];

int bfs()
{
    queue<PII> q;
    while (!q.empty())
        q.pop();
    vis[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;
        if (x == ex && y == ey)
            return vis[x][y];
        for (int i = 0; i < 8; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx <= 0 || ny <= 0 || nx > 8 || ny > 8 || vis[nx][ny] != -1)
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    char s[3], e[3];
    while (scanf("%s%s", s, e) != EOF)
    {
        sx = s[1] - '0', sy = s[0] - 'a' + 1;
        ex = e[1] - '0', ey = e[0] - 'a' + 1;
        memset(vis, -1, sizeof(vis));
        int ans = bfs();
        printf("%s==>%s: %d moves\n", s, e, ans);
    }

    return 0;
}
