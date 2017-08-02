//Asteroids POJ3014

/*Sample Input
3 4
1 1
1 3
2 2
3 2
*/

#include <iostream>
#include <cstring>
#include <vector>
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

const int maxv = 10005;
int n, k, V;
vector<int> G[maxv];
int match[maxv];
bool vis[maxv];

void addedge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

// 增广路
bool dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i], w = match[u];
        if (w < 0 || !vis[w] && dfs(w))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

// 二分图最大匹配
int hungary()
{
    int ans = 0;
    clr(match, -1);
    for (int v = 0; v < V; v++)
    {
        if (match[v] < 0)
        {
            clr(vis, 0);
            if (dfs(v))
                ans++;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    V = n * 2;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        addedge(r - 1, n + c - 1);
    }
    cout << hungary() << endl;
    return 0;
}
