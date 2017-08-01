// Til the Cows Come Home, POJ2387

/*Sample Input
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
*/

#include <iostream>
#include <cstring>
#include <queue>
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
typedef vector<PII> VII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 2005;
VII G[maxn];
int vis[maxn], dis[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int w)
{
    G[u].pb(mp(w, v));
}

void dijk(int s, int n)
{
    clr(vis, 0);
    clr(dis, 0x3f);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> > q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        PII t = q.top();
        int x = t.Y;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].Y;
            int w = G[x][i].X;
            if (!vis[y] && dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(mp(dis[y], y));
            }
        }
    }
}

int main()
{
    fastin
    int t, n;
    cin >> t >> n;
    init(n);
    while (t--)
    {
        int a, b, val;
        cin >> a >> b >> val;
        a--, b--;
        add_edge(a, b, val);
        add_edge(b, a, val);
    }
    dijk(0, n);
    cout << dis[n - 1] << endl;
    return 0;
}
