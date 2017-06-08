#include <bits/stdc++.h>
using namespace std;

int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};
int n;
int vis[52][52];
char maze[52][52];
typedef pair<int, int> PII;

void bfs()
{
    queue<PII> q;
    while (!q.empty())
        q.pop();
    q.push(make_pair(0, 0));
    vis[0][0] = 0;
    while (!q.empty())
    {
        PII temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            int cost;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (maze[x][y] == '#' || maze[nx][ny] == '#')
                cost = vis[x][y] + 1;
            else
                cost = vis[x][y];
            if (vis[nx][ny] == -1 || cost < vis[nx][ny])
            {
                vis[nx][ny] = cost;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        memset(vis, -1, sizeof(vis));
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        bfs();
        cout << vis[n - 1][n - 1] << endl;
    }
    return 0;
}
