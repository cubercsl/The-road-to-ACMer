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

const int maxn = 105;
int G[maxn][maxn];
int g[maxn][maxn];

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
        int n, x, y, l;
        scanf("%d%d%d%d", &n, &x, &y, &l);
        clr(G, 0x3f);
        clr(g, 0x3f);
        while (x--)
        {
            static int a, b;
            scanf("%d%d", &a, &b);
            G[a][b] = G[b][a] = min(G[a][b], 1);
            g[a][b] = g[b][a] = min(g[a][b], 0);
        }
        while (y--)
        {
            static int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            G[u][v] = G[v][u] = min(G[u][v], c);
            g[u][v] = g[v][u] = min(g[u][v], c);
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    if (g[i][j] > g[i][k] + g[k][j] && G[i][k] + G[k][j] <= l)
                        g[i][j] = g[i][k] + g[k][j], G[i][j] = G[i][k] + G[k][j];
                }
        if (g[1][n] > l)
            puts("-1");
        else
            printf("%d\n", g[1][n]);
    }
    return 0;
}
