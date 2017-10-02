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

typedef pair<PII, bool> node;
const int maxn = 105;
char maze[maxn][maxn];
int vis[maxn][maxn][2];
int tx[] = { -1, 0, 1, 0 };
int ty[] = { 0, -1, 0, 1 };

int bfs(PII S, PII T, int n, int m)
{
    clr(vis, -1);
    queue<node> q;
    q.push(mp(S, 0));
    vis[S.X][S.Y][0] = 0;
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();
        int x = tmp.X.X, y = tmp.X.Y;
        bool p = tmp.Y;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (~vis[nx][ny][p]) continue;
            if (maze[nx][ny] == '#') continue;
            if (p && maze[nx][ny] == '~') continue;
            if (!p && maze[nx][ny] == 'w') continue;
            vis[nx][ny][p] = vis[x][y][p] + 1;
            PII nxt = mp(nx, ny);
            if (nxt == T) return vis[nx][ny][p];
            q.push(mp(nxt, p));
        }
        if (maze[x][y] == '@' && vis[x][y][p ^ 1] == -1)
        {
            vis[x][y][p ^ 1] = vis[x][y][p] + 1;
            q.push(mp(tmp.X, p ^ 1));
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        PII S, T;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] == 'S')
                    S = mp(i, j);
                else if (maze[i][j] == 'T')
                    T = mp(i, j);
        int ans = bfs(S, T, n, m);
        if (~ans)
            printf("%d\n", ans);
        else
            puts("Sad Yaoge!");
    }
    return 0;
}
