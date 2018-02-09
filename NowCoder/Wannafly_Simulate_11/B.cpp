#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 505;
char maze[N][N];
int n, m, sx, sy, ex, ey;
int vis[N][N][2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int bfs()
{
    clr(vis, -1);
    queue<pair<PII, bool> > q;
    vis[sx][sy][0] = 0;
    q.push({mp(sx, sy), 0});
    while (!q.empty())
    {
        pair<PII, bool> tmp = q.front();
        q.pop();
        int x = tmp.X.X, y = tmp.X.Y;
        bool can = tmp.Y;
        if (x == ex && y == ey) return vis[x][y][can];

        for (int i = 0; i < 4; i++)
        {
            bool nextcan = can;
            int tx = x + dx[i], ty = y + dy[i];
            if (maze[tx][ty] == 'W') continue;
            if (!can && maze[tx][ty] == 'D') continue;
            if (maze[tx][ty] == 'K') nextcan = 1;
            if (~vis[tx][ty][nextcan]) continue;
            vis[tx][ty][nextcan] = vis[x][y][can] + 1;
            q.push({mp(tx, ty), nextcan});
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

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
                sx = i, sy = j;
            if (maze[i][j] == 'E')
                ex = i, ey = j;
        }

    cout << bfs() << endl;
    return 0;
}