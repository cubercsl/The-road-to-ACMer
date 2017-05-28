// Find a way, HDU2612

/*Sample Input
4 4
Y.#@
....
.#..
@..M
4 4
Y.#@
....
.#..
@#.M
5 5
Y..@.
.#...
.#...
@..M.
#...#
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 202;
char maze[maxn][maxn];
int N, M;
const int INF = 0x3f3f3f3f;
const int tx[] = {-1, 0, 1, 0};
const int ty[] = {0, -1, 0, 1};

void bfs(int init_x, int init_y, int vis[][maxn])
{
    queue<pair<int, int> > q;
    while (!q.empty())
        q.pop();
    vis[init_x][init_y] = 0;
    q.push(make_pair(init_x, init_y));
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (vis[nx][ny])
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
    int visy[maxn][maxn];
    int vism[maxn][maxn];
    int y_x, y_y, m_x, m_y;
    while (cin >> N >> M)
    {
        memset(visy, 0, sizeof(visy));
        memset(vism, 0, sizeof(vism));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'Y')
                    y_x = i, y_y = j;
                else if (maze[i][j] == 'M')
                    m_x = i, m_y = j;
            }
        bfs(m_x, m_y, vism);
        bfs(y_x, y_y, visy);
        int ans = INF;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (maze[i][j] == '@' && visy[i][j] && vism[i][j])
                    ans = min(ans, visy[i][j] + vism[i][j]);
            }
        cout << (ans * 11) << endl;
    }
    return 0;
}
