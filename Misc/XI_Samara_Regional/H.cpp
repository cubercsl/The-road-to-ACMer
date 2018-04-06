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

const int N = 200005;
int vis[N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, d;
    clr(vis, -1);
    cin >> n >> m >> d;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) cin >> maze[i];
    queue<PII> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maze[i][j] == 'M') q.push({i, j}), vis[i * m + j] = 0;
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.X, y = tmp.Y;
        if (vis[x * m + y] == d) continue;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            int id = tx * m + ty;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || ~vis[id]) continue;
            vis[id] = vis[x * m + y] + 1;
            q.push({tx, ty});
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << vis[i * m + j] << " ";
    //     cout << endl;
    // }

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maze[i][j] == 'S')
                sx = i, sy = j;
            else if (maze[i][j] == 'F')
                ex = i, ey = j;
    // cout << ex << " " << ey << endl;
    // cout << "---" << endl;
    // cout << vis[ex * m + ey] << endl;
    if (~vis[ex * m + ey] || ~vis[sx * m + sy]) return cout << -1 << endl, 0;
    q.push({sx, sy});
    vis[sx * m + sy] = 0;
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.X, y = tmp.Y;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            int id = tx * m + ty;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || ~vis[id]) continue;
            vis[id] = vis[x * m + y] + 1;
            q.push({tx, ty});
        }
    }
    cout << vis[ex * m + ey] << endl;
    return 0;
}
