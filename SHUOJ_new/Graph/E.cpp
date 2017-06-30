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

const int maxn = 32;
int L, R, C;
char maze[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int tx[] = {1, 0, -1, 0, 0, 0};
int ty[] = {0, 1, 0, -1, 0, 0};
int tz[] = {0, 0, 0, 0, 1, -1};
typedef pair<PII, int> PIII;

PIII st;

void bfs()
{
    queue <PIII> q;
    while (!q.empty())
        q.pop();
    q.push(st);
    while (!q.empty())
    {
        PIII tmp = q.front();
        q.pop();
        PII loc = tmp.first;
        int z = tmp.second;
        int x = loc.first, y = loc.second;
        for (int i = 0; i < 6; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            int nz = z + tz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L || vis[nx][ny][nz] != -1)
                continue;
            vis[nx][ny][nz] = vis[x][y][z] + 1;
            q.push(mp(mp(nx, ny), nz));
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (scanf("%d%d%d", &L, &R, &C) != EOF)
    {
        if (L + R + C == 0)
            break;
        int ex, ey, ez;
        clr(vis, -1);
        for (int k = 0; k < L; k++)
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                {
                    cin >> maze[i][j][k];
                    if (maze[i][j][k] == 'S')
                        vis[i][j][k] = 0, st = mp(mp(i, j), k);
                    else if (maze[i][j][k] == '#')
                        vis[i][j][k] = INF;
                    else if (maze[i][j][k] == 'E')
                        ex = i, ey = j, ez = k;
                }
        bfs();
        int ans = vis[ex][ey][ez];
        if (ans != -1)
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}
