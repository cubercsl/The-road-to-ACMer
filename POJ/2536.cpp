// Gopher II, POJ2536

/*Sample Input
2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
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

typedef pair<double, double> P;
const int maxn = 205;
int n, m, s, v;
P g[maxn];
bool G[maxn][maxn];
int linker[maxn];
bool used[maxn];

double dist(P a, P b)
{
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

bool dfs(int u)
{
    for (int v = 0; v < m; v++)
        if (G[u][v] && !used[v])
        {
            used[v] = true;
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
    int res = 0;
    clr(linker, -1);
    for (int u = 0; u < n; u++)
    {
        clr(used, 0);
        if (dfs(u))res++;
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n >> m >> s >> v)
    {
        clr(G, 0);
        for (int i = 0; i < n; i++)
            cin >> g[i].X >> g[i].Y;
        for (int i = 0; i < m; i++)
        {
            double x, y;
            cin >> x >> y;
            P h = mp(x, y);
            for (int j = 0; j < n; j++)
            {
                double d = dist(g[j], h);
                if (d / v <= s)
                    G[j][i] = 1;
            }
        }
        cout << n - hungary() << endl;
    }
    return 0;
}
