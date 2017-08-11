// Robot, UVa314

/*Sample Input
9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 south
0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 55;
bool maze[maxn][maxn];
int tx[] = { -1, 0, 1, 0};
int ty[] = {0, 1, 0, -1};
int n, m, sx, sy, ex, ey, sd;
int vis[maxn][maxn][4];
string dir;

struct node
{
    int x, y, dir;
    node(int _x, int _y, int _dir)
    {
        x = _x, y = _y, dir = _dir;
    }
};

int get_dir(string s)
{
    if (s[0] == 'n')
        return 0;
    if (s[0] == 'e')
        return 1;
    if (s[0] == 's')
        return 2;
    if (s[0] == 'w')
        return 3;
    return -1;
}

int bfs()
{
    queue <node> q;
    vis[sx][sy][sd] = 0;
    q.push(node(sx, sy, sd));
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();
        int x = tmp.x;
        int y = tmp.y;
        int d = tmp.dir;
        if (x == ex && y == ey)
            return vis[x][y][d];
        for (int i = 1; i <= 3; i++)
        {
            int nx = x + tx[d] * i;
            int ny = y + ty[d] * i;
            if (nx <= 0 || ny <= 0 || nx >= n || ny >= m)
                continue;
            if (maze[nx][ny])break;
            if (vis[nx][ny][d] == -1)
            {
                vis[nx][ny][d] = vis[x][y][d] + 1;
                q.push(node(nx, ny, d));
            }
        }
        int nd = (d + 1) % 4;
        if (vis[x][y][nd] == -1)
        {
            vis[x][y][nd] = vis[x][y][d] + 1;
            q.push((node(x, y, nd)));
        }
        nd = (d - 1 + 4) % 4;
        if (vis[x][y][nd] == -1)
        {
            vis[x][y][nd] = vis[x][y][d] + 1;
            q.push((node(x, y, nd)));
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> m, m + n)
    {
        clr(maze, 0);
        clr(vis, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                bool flag;
                cin >> flag;
                maze[i][j] |= flag;
                maze[i + 1][j] |= flag;
                maze[i][j + 1] |= flag;
                maze[i + 1][j + 1] |= flag;
            }
        cin >> sx >> sy >> ex >> ey >> dir;
        sd = get_dir(dir);
        int ans = bfs();
        cout << ans << endl;
    }
    return 0;
}
