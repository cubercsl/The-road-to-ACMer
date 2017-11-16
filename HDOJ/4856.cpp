#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 0x3f3f3f3f;
int tx[] = {0, -1, 0, 1};
int ty[] = {-1, 0, 1, 0};

struct Pipe
{
    int x1, y1, x2, y2;
    inline void read()
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1, --y1, --x2, --y2;
    }
} P[N];

int n, m;
char maze[N][N];
int d[N][N];

int bfs(Pipe a, Pipe b)
{
    queue<pair<int, int> > q;
    memset(d, -1, sizeof(d));
    d[a.x2][a.y2] = 0;
    q.push(make_pair(a.x2, a.y2));
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        if (x == b.x1 && y == b.y1) return d[x][y];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (maze[nx][ny] == '#') continue;
            if (~d[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}

int dp[(1 << 15) + 5][N];
int G[N][N];

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++) scanf("%s", maze[i]);
        for (int i = 0; i < m; i++) P[i].read();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                G[i][j] = i == j ? 0 : bfs(P[i], P[j]);
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < m; i++) dp[1 << i][i] = 0;
        for (int i = 0; i < (1 << m); i++)
            for (int j = 0; j < m; j++)
                if (dp[i][j] != INF)
                    for (int k = 0; k < m; k++)
                        if (!(i & (1 << k)) && ~G[j][k])
                            dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + G[j][k]);
        int ans = INF;
        for (int i = 0; i < m; i++) ans = min(ans, dp[(1 << m) - 1][i]);
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}