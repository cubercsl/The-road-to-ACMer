// Air Raid, POJ1422

/*Sample Input
2
4
3
3 4
1 3
2 3
3
3
1 3
1 2
2 3
*/

#include <iostream>
#include <vector>
#include <cstring>
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

const int maxn = 125;
int n;
bool g[maxn][maxn];
int linker[maxn];
bool used[maxn];
bool dfs(int u)
{
    for (int v = 0; v < n; v++)
        if (g[u][v] && !used[v])
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
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        clr(g, 0);
        int k;
        cin >> n >> k;
        while (k--)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x][y] = 1;
        }
        cout << n - hungary() << endl;
    }
    return 0;
}
