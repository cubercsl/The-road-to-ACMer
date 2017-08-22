// Selecting Courses, POJ2239

/*Sample Input
5
1 1 1
2 1 1 2 2
1 2 2
2 3 2 3 3
1 3 3
*/

#include <cstdio>
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

const int maxn = 600;
int n;
vector<int> G[maxn];
int linker[maxn];
bool vis[maxn];
void addedge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

bool dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i], w = linker[u];
        if (w < 0 || !vis[w] && dfs(w))
        {
            linker[v] = u;
            linker[u] = v;
            return true;
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    clr(linker, -1);
    for (int v = 0; v < n; v++)
    {
        if (linker[v] < 0)
        {
            clr(vis, 0);
            if (dfs(v)) ans++;
        }
    }
    return ans;
}

int main()
{
    int _, p, q;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
        for (int i = 0; i < n; i++)
        {
            for (scanf("%d", &_); _; _--)
            {
                scanf("%d%d", &p, &q);
                addedge(i, n + 12 * p + q - 13);
            }
        }
        printf("%d\n", hungary());
    }
    return 0;
}
