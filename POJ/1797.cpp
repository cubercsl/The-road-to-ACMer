// Heavy Transportation, POJ1797

/*Sample Input
1
3 3
1 2 3
1 3 4
2 3 5
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
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

const int maxn = 1005;
typedef pair<int, PII> edge;
vector<edge> G;
int par[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void add_edge(int u, int v, int d)
{
    G.pb(mp(d, mp(u, v)));
}

bool cmp (edge a, edge b)
{
    return a > b;
}

int kruskal(int n)
{
    init(n);
    sort(G.begin(), G.end(), cmp);
    int m = G.size();
    int num = 0, ret = 0;
    for (int i = 0; i < m; i++)
    {
        edge p = G[i];
        int x = p.Y.X;
        int y = p.Y.Y;
        int d = p.X;
        unite(x, y);
        if (same(0, n - 1))
            return d;
    }
}

int main()
{
    fastin
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        G.clear();
        int n, m;
        cin >> n >> m;
        while (m--)
        {
            int u, v, d;
            cin >> u >> v >> d;
            u--, v--;
            add_edge(u, v, d);
        }
        cout << "Scenario #" << ++kase << ":" << endl;
        cout << kruskal(n) << endl << endl;
    }
    return 0;
}
