// Currency Exchange, POJ1860

/*Sample Input
3 2 1 20.0
1 2 1.00 1.00 1.00 1.00
2 3 1.10 1.00 1.10 1.00
*/

#include <iostream>
#include <cstring>
#include <queue>
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
bool G[maxn][maxn];
double d[maxn];
double r[maxn][maxn], c[maxn][maxn];

bool bfs(int s, double v, int n)
{
    queue<int> q;
    d[s] = v;
    q.push(s);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (t == s && d[t] > v)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (G[t][i])
            {
                double tmp = (d[t] - c[t][i]) * r[t][i];
                if (tmp > d[i])
                {
                    d[i] = tmp;
                    q.push(i);
                }
            }
        }
    }
    return false;
}

int main()
{
    fastin
    int n, m, s;
    double v;
    while (cin >> n >> m >> s >> v)
    {
        clr(G, 0);
        clr(r, 0);
        clr(c, 0);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            G[u][v] = G[v][u] = 1;
            cin >> r[u][v] >> c[u][v];
            cin >> r[v][u] >> c[v][u];
        }
        if (bfs(--s, v, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
