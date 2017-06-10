#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int m, n, a, b, c, d;
int vis[22][22];
int tx[] = { -2, -1, 1, 2};
int ty[] = {1, 2, 2, 1};

int bfs()
{
    queue<PII> q;
    while (!q.empty())
        q.pop();
    vis[a][b] = 0;
    q.push(make_pair(a, b));
    while (!q.empty())
    {
        PII temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        if (x == c && y == d)
            return vis[x][y];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 1 || nx > m || ny < 1 || ny > n)
                continue;
            if (vis[nx][ny] != -1)
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}

int main()
{
    while (cin >> m >> n)
    {
        cin >> a >> b >> c >> d;
        memset(vis, -1, sizeof(vis));
        int ans = bfs();
        ans != -1 ? cout << ans << endl : cout << "Impossible" << endl;
    }
    return 0;
}
