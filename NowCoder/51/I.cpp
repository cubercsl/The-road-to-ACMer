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

const int tx[] = {-1, 0, 1, 0};
const int ty[] = {0, -1, 0, 1};

const int N = 1005;
typedef pair<PII, int> Node;
int vis[N][N][6];
char maze[N][N];
int bfs(const int& n, const int& m, const int& r, const int& c)
{
    clr(vis, -1);
    if (r == 0 && c == 0) return 0;
    vis[0][0][0] = 0;
    queue<Node> q;
    q.push(mp(mp(0, 0), 0));
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        int x = tmp.X.X, y = tmp.X.Y;
        int ok = tmp.Y;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i], ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[nx][ny] == '*') continue;
            int flag = ok;
            if (maze[nx][ny] == 'M' && flag % 3 == 1) continue;
            if (maze[nx][ny] == 'F' && flag % 3 == 2) continue;
            if (maze[nx][ny] == 'M' && flag % 3 == 0) flag += 2;
            if (maze[nx][ny] == 'F' && flag % 3 == 0) flag += 1;
            if (nx == r && ny == c && flag < 3) flag += 3;
            if (~vis[nx][ny][flag]) continue;
            vis[nx][ny][flag] = vis[x][y][ok] + 1;
            // printf("%d %d %d\n", nx, ny, flag);
            if (nx == 0 && ny == 0 && flag > 2) return vis[0][0][flag];
            q.push(mp(mp(nx, ny), flag));
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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, r, c;
        scanf("%d%d%d%d", &n, &m, &r, &c);
        --r, --c;
        for (int i = 0; i < n; i++) scanf("%s", maze[i]);
        int ans = bfs(n, m, r, c);
        if (~ans)
            printf("%d\n", ans);
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
