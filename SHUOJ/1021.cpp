#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
char maze[102][102];
int vis[102][102];
int n, m, sx, sy, ex, ey;
typedef pair<int, int> PII;
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

void bfs()
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
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] != -1)
                continue;
            if (maze[nx][ny] == '#')
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, -1, sizeof(vis));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'S')
                    sx = i, sy = j;
                else if (maze[i][j] == 'E')
                    ex = i, ey = j;
            }
        bfs();
        cout << vis[ex][ey] << endl;
    }
    return 0;
}
