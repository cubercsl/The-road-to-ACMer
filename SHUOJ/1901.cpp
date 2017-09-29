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

int tx[] = { -1, 0, 1, 0 };
int ty[] = { 0, -1, 0, 1 };
struct node
{
    int state;
    PII a, b;
    node(int s, PII _a, PII _b) : state(s), a(_a), b(_b) {}
};
char G[5][5];
int dis[1 << 24 | 1];
int n, m;
int bfs(int sx, int sy, int tar)
{
    int id = sx * m + sy;
    int st = 1 << id;
    st = (st << 4) + id;
    st = (st << 4) + id;
    clr(dis, 0);
    queue<node> q;
    q.push(node(st, mp(sx, sy), mp(sx, sy)));
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();
        int now = tmp.state;
        int xa = tmp.a.X, ya = tmp.a.Y;
        int xb = tmp.b.X, yb = tmp.b.Y;
        for (int i = 0; i < 4; i++)
        {
            int x1 = xa + tx[i];
            int y1 = ya + ty[i];
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
            if (G[x1][y1] == 'X') continue;
            for (int j = 0; j < 4; j++)
            {
                int x2 = xb + tx[j];
                int y2 = yb + ty[j];
                if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m) continue;
                if (G[x2][y2] == 'X') continue;
                int nxt = ((now >> 8) | (1 << (x1 * m + y1)) | (1 << (x2 * m + y2)));
                nxt = (nxt << 4) + (x1 * m + y1);
                nxt = (nxt << 4) + (x2 * m + y2);
                if (dis[nxt]) continue;
                dis[nxt] = dis[now] + 1;
                if ((nxt >> 8) == tar) return dis[nxt];
                q.push(node(nxt, mp(x1, y1), mp(x2, y2)));
            }
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
        int tar = 0;
        int x, y;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", G[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (G[i][j] == 'O')
                    tar |= (1 << (i * m + j));
                else if (G[i][j] == 'S')
                    x = i, y = j, tar |= (1 << (i * m + j));
        int ans = bfs(x, y, tar);
        printf("%d\n", ans);
    }
    return 0;
}
