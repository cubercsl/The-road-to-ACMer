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

const int N = 105;
char s[N][N];
int n, m;
int sx, sy, ex, ey;
int xx[3], yy[3], tt[3];
int vis[N][N][1 << 3];

struct Node
{
    int x, y, state;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs()
{
    clr(vis, 0x3f);
    queue<Node> q;
    q.push({sx, sy, 0});
    vis[sx][sy][0] = 0;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        int &x = tmp.x, &y = tmp.y, &state = tmp.state;
        for (int i = 0; i < 4; i++)
        {
            int nstate = state;
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
            if (state == 7 && s[tx][ty] == '#') continue;
            for (int i = 0; i < 3; i++)
                if (tx == xx[i] && ty == yy[i]) nstate |= 1 << i;
            int w = 1;
            for (int i = 0; i < 3; i++)
                if (state >> i & 1) w += tt[i];
            if (vis[tx][ty][state] > vis[x][y][state] + w)
            {
                vis[tx][ty][state] = vis[x][y][state] + w;
                q.push({tx, ty, state});
            }
            if (vis[tx][ty][nstate] > vis[x][y][state] + w)
            {
                vis[tx][ty][nstate] = vis[x][y][state] + w;
                q.push({tx, ty, nstate});
            }
        }
    }
    return vis[ex][ey][7];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    scanf("%d%d", &sx, &sy), --sx, --sy;
    for (int i = 0; i < 3; i++) scanf("%d%d", &xx[i], &yy[i]), --xx[i], --yy[i];
    scanf("%d%d", &ex, &ey), --ex, --ey;
    for (int i = 0; i < 3; i++) scanf("%d", &tt[i]);
    printf("%d\n", bfs());
    return 0;
}