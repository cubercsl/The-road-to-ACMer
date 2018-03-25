#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, m;
char maze[N][N];

int f[N][N];
int v[N][N];
typedef pair<int, int> PII;

void bfs_fire(int x, int y)
{
    memset(f, -1, sizeof(f));
    queue<PII> q;
    f[x][y] = 0;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.first, y = tmp.second;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (i || j)
                {
                    int nx = x + i, ny = y + j;
                    if (nx < 0 || ny < 0 || nx >= n || nx >= m) continue;
                    if (~f[nx][ny]) continue;
                    f[nx][ny] = f[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
    }
    /*for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            printf("%d%c", f[i][j], j != m - 1 ? ' ' : '\n');
    */
}

const int tx[] = {-1, 0, 1, 0};
const int ty[] = {0, -1, 0, 1};

int bfs(int sx, int sy, int ex, int ey)
{
    memset(v, -1, sizeof(v));
    queue<PII> q;
    v[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.first, y = tmp.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || nx >= m) continue;
            if (~v[nx][ny] || maze[nx][ny] == '#') continue;
            if (nx == ex && ny == ey && v[x][y] + 1 <= f[nx][ny])
            {
                v[nx][ny] = v[x][y] + 1;
                return v[nx][ny];
            }
            if (v[x][y] + 1 >= f[nx][ny]) continue;
            v[nx][ny] = v[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        int fx, fy, sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'S') sx = i, sy = j;
                if (maze[i][j] == 'E') ex = i, ey = j;
                if (maze[i][j] == '*') fx = i, fy = j;
            }
        bfs_fire(fx, fy);
        int ans = bfs(sx, sy, ex, ey);
        if (~ans)
            printf("%d\n", ans);
        else
            puts("T_T");
    }
    return 0;
}
