// The Unique MST, POJ1679

/*Sample Input
2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
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
int par[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++) par[i] = i;
}
int find(int x)
{
    return par[x] != x ? par[x] = find(par[x]) : x;
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
inline void unite(int x, int y)
{
    x = find(x), y = find(y);
    par[y] = x;
}
typedef pair<int, PII> edge;
vector<edge> V;
vector<PII> G[maxn];
inline void add_edge(int u, int v, int w)
{
    V.pb(mp(w, mp(u, v)));
}

bool vis[maxn];
int dp[maxn][maxn];
void dfs(int u, int n)
{
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].X, w = G[u][i].Y;
        if (vis[v]) continue;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j]) continue;
            dp[j][v] = dp[v][j] = max(dp[j][v], w);
        }
        dfs(v, n);
    }
}
int krusakl(int n)
{
    sort(V.begin(), V.end());
    init(n);
    for (int i = 0; i <= n; i++) G[i].clear();
    vector<edge> T;
    int cnt = 0, mst = 0;
    int i;
    for (i = 0; i < V.size(); i++)
    {
        int u = V[i].Y.X, v = V[i].Y.Y;
        int w = V[i].X;

        if (!same(u, v))
        {
            // printf("u = %d, v = %d\n", u, v);
            unite(u, v);
            mst += w;
            G[u].pb(mp(v, w)), G[v].pb(mp(u, w));
            if (++cnt == n - 1) break;
        }
        else
            T.pb(V[i]);
    }
    // printf("%d\n", i);
    for (i++; i < V.size(); i++)
        T.pb(V[i]);
    clr(vis, 0);
    clr(dp, 0);
    dfs(V[0].Y.X, n);
    /*
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("dp[%d][%d] = %d%c", i, j, dp[i][j], j == n ? '\n' : ' ');
    */
    int smst = INF;
    for (int i = 0; i < T.size(); i++)
    {
        int u = T[i].Y.X, v = T[i].Y.Y;
        int w = T[i].X;
        // printf("u = %d, v = %d\n", u, v);
        smst = min(mst - dp[u][v] + w, smst);
    }
    if (mst != smst) return mst;
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
        int n, m;
        V.clear();
        scanf("%d%d", &n, &m);
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        int ans = krusakl(n);
        if (~ans)
            printf("%d\n", ans);
        else
            puts("Not Unique!");
    }
    return 0;
}
