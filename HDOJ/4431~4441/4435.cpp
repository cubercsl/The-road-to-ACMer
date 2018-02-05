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

const int N = 1 << 7;
bool can[N];
int G[N][N];
PII a[N];
inline double dis(PII a, PII b)
{
    double dx = a.X - b.X, dy = a.Y - b.Y;
    return ceil(sqrt(dx * dx + dy * dy));
}
bool bfs(const int& n, const int& d)
{
    bool vis[N];
    clr(vis, 0);
    int dis[N];
    for (int i = 0; i < n; i++) dis[i] = can[i] ? 0 : INF;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] || G[x][i] > d) continue;
            dis[i] = min(dis[i], dis[x] + G[x][i]);
            if (can[i]) q.push(i);
        }
    }
    for (int i = 0; i < n; i++)
        if (can[i] && !vis[i] || !can[i] && 2 * dis[i] > d) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, d;
    while (~scanf("%d%d", &n, &d))
    {
        clr(can, 1);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[i].X, &a[i].Y);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = dis(a[i], a[j]);

        if (!bfs(n, d))
        {
            puts("-1");
            continue;
        }
        for (int i = n - 1; ~i; i--)
        {
            can[i] = 0;
            if (!bfs(n, d)) can[i] = 1;
        }
        int j = n - 1;
        while (!can[j]) j--;
        for (int i = j; ~i; i--) printf("%d", can[i]);
        puts("");
    }
    return 0;
}
