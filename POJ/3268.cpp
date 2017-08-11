// Silver Cow Party, POJ3268

/*Sample Input
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
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

const int maxn = 1e3 + 5;
const int maxm = 1e5 + 5;
typedef vector<PII> VII;
VII G[maxn];
bool vis[maxn];
int dis[maxn], ans[maxn];
int u[maxm], v[maxm], w[maxm];

void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int w)
{
    G[u].pb(mp(w, v));
}

void Dijkstra(int s, int n)
{
    clr(dis, 0x3f);
    clr(vis, 0);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> > q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        PII t = q.top();
        q.pop();
        int x = t.Y;
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
    for (int i = 0; i < n; i++)
        ans[i] += dis[i];
}

int main()
{
    fastin
    int n, m, x;
    while (cin >> n >> m >> x)
    {
        clr(ans, 0);
        init(n);
        x--;
        for (int i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i] >> w[i];
            u[i]--, v[i]--;
            add_edge(u[i], v[i], w[i]);
        }
        Dijkstra(x, n);
        init(n);
        for (int i = 0; i < m; i++)
            add_edge(v[i], u[i], w[i]);
        Dijkstra(x, n);
        cout << *max_element(ans, ans + n) << endl;
    }
    return 0;
}
