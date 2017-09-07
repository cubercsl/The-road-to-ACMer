#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

const int maxn = 25;
int G[maxn][maxn];
bool vis[maxn][maxn];
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};
int n, m;

void dfs(int x, int y, int flag)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (vis[x][y]) return;
    if (G[x][y] != flag) return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        dfs(x + tx[i], y + ty[i], flag);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> m, n + m)
    {
        clr(G, 0);
        clr(vis, 0);
        int cnt = 0;
        int k;
        cin >> k;
        for (int t = 0; t < k; t++)
        {
            int x1, x2, y1, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            for (int i = x1; i < x2; i++)
                for (int j = y1; j < y2; j++)
                    G[i][j] += (1 << t);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j])
                {
                    dfs(i, j, G[i][j]);
                    cnt++;
                }
        cout << cnt << endl;
    }
    return 0;
}
