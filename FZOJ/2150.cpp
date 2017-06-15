// Fire Game, FZU2150

/*Sample Input
4
3 3
.#.
###
.#.
3 3
.#.
#.#
.#.
3 3
...
#.#
...
3 3
###
..#
#.#
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};
const int maxn = 12;
const int INF = 0x3f3f3f3f;

int N, M;
char maze[maxn][maxn];
int vis[maxn][maxn];

int bfs(PII a, PII b)
{
    int ans = 0;
    vis[a.first][a.second] = 0;
    vis[b.first][b.second] = 0;
    queue<PII> q;
    while (!q.empty())
        q.pop();
    q.push(a);
    q.push(b);
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
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (vis[nx][ny] != -1)
                continue;
            if (maze[nx][ny] != '#')
                continue;
            ans = vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return ans;
}

bool judge()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (maze[i][j] == '#' && vis[i][j] == -1)
                return false;
    return true;
}

int main()
{
    int t;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        int ans = INF;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> maze[i][j];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (maze[i][j] == '#')
                    for (int k = 0; k < N; k++)
                        for (int l = 0; l < M; l++)
                            if (maze[k][l] == '#')
                            {
                                memset(vis, -1, sizeof(vis));
                                int temp = bfs(make_pair(i, j), make_pair(k, l));
                                if (judge())
                                    ans = min(ans, temp);
                            }
        if (ans == INF)
            ans = -1;
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}
