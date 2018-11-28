#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int n, m;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int r, int c)
{
    vis[r][c] = 1;
    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '#' && !vis[nr][nc])
            dfs(nr, nc);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", maze[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '#' && !vis[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", ans);
}