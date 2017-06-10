#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

char maze[22][22];
int vis[22][22][11];
typedef pair<int, int> PII;
typedef pair<PII, int> P3I;
int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};

int n, m;
int sx, sy, ex, ey, k;

void bfs()
{
    queue<P3I> q;
    while (!q.empty())
        q.pop();
    vis[sx][sy][k] = 0;
    q.push(make_pair(make_pair(sx, sy), k));
    while (!q.empty())
    {
        P3I tmp = q.front();
        q.pop();
        PII loc = tmp.first;
        int rem = tmp.second;
        int x = loc.first;
        int y = loc.second;
        int cost = vis[x][y][rem];
        if (x == ex && y == ey)
            return;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (maze[x][y] == 'x' && maze[nx][ny] == 'x')
                continue;
            if (maze[x][y] != 'x' && maze[nx][ny] == 'x' && rem > 0)
                if (vis[nx][ny][rem - 1] != -1)
                    continue;
                else
                {
                    vis[nx][ny][rem - 1] = cost + 1;
                    q.push(make_pair(make_pair(nx, ny), rem - 1));
                }
            else if (maze[nx][ny] != 'x')
                if (vis[nx][ny][rem] != -1)
                    continue;
                else
                {
                    vis[nx][ny][rem] = cost + 1;
                    q.push(make_pair(make_pair(nx, ny), rem));
                }
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
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'S')
                    sx = i, sy = j;
                else if (maze[i][j] == 'T')
                    ex = i, ey = j;
            }
        bfs();
        int ans = INF;
        for (int i = 0; i <= k; i++)
            //    cout<<vis[ex][ey][i]<<endl;
            if (vis[ex][ey][i] != -1)
                ans = min(ans, vis[ex][ey][i]);
        ans != INF ? cout << ans : cout << -1;
        cout << endl;
    }
    return 0;
}
