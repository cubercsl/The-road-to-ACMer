// Sightseeing trip, POJ734

/*Sample Input
5 7
1 4 1
1 3 300
3 1 10
1 2 16
2 3 100
2 5 15
5 3 20
*/

#include <cstring>
#include <iostream>
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
int G[maxn][maxn];
int d[maxn][maxn];
int pre[maxn][maxn];
vector<int> path;
void init(int n)
{
    clr(G, 0x3f);
    clr(d, 0x3f);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pre[i][j] = i;
}

int floyd(int n)
{
    int ans = INF;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (ans > d[i][j] + G[i][k] + G[k][j])
                {
                    ans = d[i][j] + G[i][k] + G[k][j];
                    path.clear();
                    int cur = j;
                    while (cur != i)
                        path.pb(cur), cur = pre[i][cur];
                    path.pb(i), path.pb(k);
                }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pre[i][j] = pre[k][j];
                }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        while (m--)
        {
            static int u, v, w;
            cin >> u >> v >> w;
            d[u][v] = d[v][u] = G[u][v] = G[v][u] = min(G[u][v], w);
        }
        if (floyd(n) == INF)
            cout << "NO solution." << endl;
        else
        {
            for (int i = 0; i < path.size(); i++)
            {
                if (i) cout << " ";
                cout << path[i];
            }
            cout << endl;
        }
    }
    return 0;
}
