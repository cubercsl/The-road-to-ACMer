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

char maze[205][205];
int vis[205][205][105];
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};

typedef pair<PII, int> Node;
inline bool upmin(int& a, int b)
{
    if (a > b) return a = b, true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    int sx, sy, ex, ey;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    clr(vis, 0x3f);
    queue<Node> q;
    q.push(mp(mp(sx, sy), 0));
    vis[sx][sy][0] = 0;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        PII p = tmp.X;
        int &x = p.X, y = p.Y, t = tmp.Y;
        int step = vis[x][y][t];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[x][y] == '.')
            {
                if (k == 1 && maze[nx][ny] == '.' || k > 1)
                    if (upmin(vis[nx][ny][k - 1], step + 1))
                        q.push(mp(mp(nx, ny), k - 1));
                if (upmin(vis[nx][ny][0], step + 2))
                    q.push(mp(mp(nx, ny), 0));
            }
            else if (maze[x][y] == '#')
            {
                if (t == 1 && maze[nx][ny] == '.' || t > 1)
                    if (upmin(vis[nx][ny][t - 1], step + 1))
                        q.push(mp(mp(nx, ny), t - 1));
            }
            else if (maze[x][y] == 'x')
            {
                if (t == 1 && maze[nx][ny] == '.' || t > 1)
                {
                    if (upmin(vis[nx][ny][t - 1], step + 1))
                        q.push(mp(mp(nx, ny), t - 1));
                }
                else if (t == 0 && maze[x][y] != '#')
                {
                    if (upmin(vis[nx][ny][0], step + 2))
                        q.push(mp(mp(nx, ny), 0));
                }
            }
        }
    }
    int ans = vis[ex][ey][0];
    if (maze[ex][ey] == '.')
        for (int i = 1; i <= k; i++)
            ans = min(ans, vis[ex][ey][i]);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
