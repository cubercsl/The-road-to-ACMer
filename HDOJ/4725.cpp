// The Shortest Path in Nya Graph, HDU4725

/*Sample Input
2
3 3 3
1 3 2
1 2 1
2 3 1
1 3 3

3 3 3
1 3 2
1 2 2
2 3 2
1 3 4
*/

#include <bits/stdc++.h>
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

const int maxn = 3e5 + 5;
typedef vector<PII> VII;
VII G[maxn];
bool vis[maxn];
int dis[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int w)
{
    G[u].pb(mp(w, v));
}

int Dijk(int s, int t)
{
    clr(vis, 0);
    clr(dis, 0x3f);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> >q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        PII tmp = q.top();
        q.pop();
        int x = tmp.Y;
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
    if (dis[t] < INF)
        return dis[t];
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        int n, m, c;
        cin >> n >> m >> c;
        init(n * 3);
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            add_edge(i, n + 2 * t - 1, 0);
            add_edge(n + 2 * t, i, 0);
        }
        for (int i = 1; i < n; i++)
        {
            add_edge(n + 2 * i - 1, n + 2 * (i + 1), c);
            add_edge(n + 2 * (i + 1) - 1, n + 2 * i, c);
        }
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        cout << "Case #" << ++kase << ": " << Dijk(1, n) << endl;
    }
    return 0;
}
