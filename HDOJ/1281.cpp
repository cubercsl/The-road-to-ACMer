// 棋盘游戏, HDU1281

/*Sample Input
3 3 4
1 2
1 3
2 1
2 2
3 3 4
1 2
1 3
2 1
3 2
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 105;
int n, m, k;
int g[maxn][maxn];
int linker[maxn], save[maxn];
bool vis[maxn];
bool dfs(int u)
{
    for (int v = 0; v < m; v++)
        if (g[u][v] && !vis[v])
        {
            vis[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}

int hungary()
{
    int ans = 0;
    clr(linker, -1);
    for (int u = 0; u < n; u++)
    {
        clr(vis, 0);
        if (dfs(u)) ans++;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in","r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    fastin
    int kase = 0;
    while (cin >> n >> m >> k)
    {
        clr(g, 0);
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            g[a - 1][b - 1] = 1;
        }
        int ans = hungary();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            save[i] = linker[i];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
                linker[j] = save[j];
            if (linker[i] != -1)
            {
                int tmp = linker[i];
                g[tmp][i] = 0, linker[i] = -1;
                clr(vis, 0);
                if (!dfs(tmp))
                    cnt++;
                g[tmp][i] = 1;
            }
        }
        cout << "Board " << ++kase << " have " << cnt << " important blanks for " << ans << " chessmen." << endl;
    }
    return 0;
}
