// Patrol Robot,ACM/ICPC Hanoi 2006, UVa1600

/*Sample input
3
2 5
0
0 1 0 0 0
0 0 0 1 0
4 6
1
0 1 1 0 0 0
0 0 1 0 1 1
0 1 1 1 1 0
0 1 1 1 0 0
2 2
0
0 1
1 0
*/

#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 20;
int m, n, k;
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};
bool maze[maxn][maxn];
int vis[maxn][maxn][maxn];
typedef pair <PII, int> PIII;

void bfs()
{
    queue<PIII> q;
    while (!q.empty())
        q.pop();
    PII loc = mp(0, 0);
    vis[0][0][0] = 0;
    q.push(mp(loc, 0));
    while (!q.empty())
    {
        PIII tmp = q.front();
        q.pop();
        PII loc = tmp.first;
        int t_k = tmp.second;
        int x = loc.first, y = loc.second;
        // cout << "(" << x << "," << y << ") k=" << t_k << endl;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (maze[nx][ny] && t_k + 1 <= k && vis[x][y][t_k] + 1 < vis[nx][ny][t_k + 1])
            {
                vis[nx][ny][t_k + 1] = vis[x][y][t_k] + 1;
                q.push(mp(mp(nx, ny), t_k + 1));
            }
            else if (!maze[nx][ny] && vis[x][y][t_k] + 1 < vis[nx][ny][0])
            {
                vis[nx][ny][0] = vis[x][y][t_k] + 1;
                q.push(mp(mp(nx, ny), 0));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Tcase
    {
        clr(vis, 0x3f);
        cin >> m >> n >> k;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> maze[i][j];
        bfs();
        if (vis[m - 1][n - 1][0] != INF)
            cout << vis[m - 1][n - 1][0] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
