// Popular Cows, POJ2186

/*Sample Input
3 3
1 2
2 1
2 3
*/

#include <iostream>
#include <vector>
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

const int maxn = 1e4 + 5;
int N, M, V;
vector <int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;

int vis[maxn];
int cmp[maxn];

void add_edge(int u, int v)
{
    G[u].pb(v);
    rG[v].pb(u);
}

void dfs(int v)
{
    vis[v] = 1;
    for (int i = 0; i < G[v].size(); i++)
        if (!vis[G[v][i]])
            dfs(G[v][i]);
    vs.pb(v);
}

void rdfs(int v, int k)
{
    vis[v] = 1;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++)
        if (!vis[rG[v][i]])
            rdfs(rG[v][i], k);
}

int scc()
{
    clr(vis, 0);
    vs.clear();
    for (int v = 0; v < V; v++)
        if (!vis[v])
            dfs(v);
    clr(vis, 0);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
        if (!vis[vs[i]])
            rdfs(vs[i], k++);
    return k;
}

void solve()
{
    V = N;
    int n = scc();
    int u = 0, num = 0;
    for (int v = 0; v < V; v++)
    {
        if (cmp[v] == n - 1)
        {
            u = v;
            num++;
        }
    }
    clr(vis, 0);
    rdfs(u, 0);
    for (int v = 0; v < V; v++)
    {
        if (!vis[v])
        {
            num = 0;
            break;
        }
    }
    cout << num << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> N >> M;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        add_edge(a - 1, b - 1);
    }
    solve();
    return 0;
}
