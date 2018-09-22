#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
char maze[N][N];

int d[N][N][6];
bool inq[N][N][6];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        if (n + m == 0) break;
        memset(d, 0x3f, sizeof(d));
        memset(inq, false, sizeof(inq));
        for (int i = 0; i < n; i++) scanf("%s", maze[i]);
        pair<int, int> s, t;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'S') s = {i, j};
                if (maze[i][j] == 'T') t = {i, j};
            }
        queue<pair<pair<int, int>, int>> q;
        d[s.first][s.second][0] = 0;
        inq[s.first][s.second][0] = 1;
        q.push({s, 0});
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first.first;
            int y = t.first.second;
            int z = t.second;
            inq[x][y][z] = 0;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                int w = 1;
                int b = 0;
                if (maze[tx][ty] == '#') w = 2, b = -1;
                if (maze[tx][ty] == 'P') w = 0;
                if (maze[tx][ty] == 'B') b = 1;
                if (z + b < 0 || z + b > 5) continue;
                if (d[tx][ty][z + b] <= d[x][y][z] + w) continue;
                d[tx][ty][z + b] = d[x][y][z] + w;
                if (!inq[tx][ty][z + b])
                {
                    q.push({{tx, ty}, z + b});
                    inq[tx][ty][z + b] = true;
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 6; i++)
            ans = min(ans, d[t.first][t.second][i]);
        if (ans == INF) ans = -1;
        printf("%d\n", ans);
    }
}