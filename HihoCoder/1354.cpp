#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int INF = 0x3f3f3f3f;
int vis[N][N];
bool can[N][N], inq[N][N];
int a[N], b[N];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
typedef pair<int, int> PII;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) scanf("%d", b + i), b[i] += b[i - 1];
    for (int i = 1; i < m; i++) scanf("%d", a + i), a[i] += a[i - 1];
    int t;
    scanf("%d", &t);
    while (t--)
    {
        static int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        can[x][y] = 1;
    }
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        static int x, y, p, q;
        scanf("%d%d%d%d", &x, &y, &p, &q);
        --x, --y, --p, --q;
        memset(vis, 0x3f, sizeof(vis));
        queue<PII> que;
        que.push({x, y});
        vis[x][y] = 0;
        inq[x][y] = true;
        while (!que.empty())
        {
            PII tmp = que.front();
            que.pop();
            int &x = tmp.first, &y = tmp.second;
            inq[x][y] = false;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= m || can[tx][ty]) continue;
                int w = abs(b[tx] - b[x]) + abs(a[ty] - a[y]);
                if (vis[x][y] + w < vis[tx][ty])
                {
                    vis[tx][ty] = vis[x][y] + w;
                    if (!inq[tx][ty])
                        que.push({tx, ty}), inq[tx][ty] = true;
                }
            }
        }
        printf("%d\n", vis[p][q] != INF ? vis[p][q] : -1);
    }
    return 0;
}
