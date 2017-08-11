// Invitation Cards, POJ1511

/*Sample Input
2
2 2
1 2 13
2 1 33
4 6
1 2 10
2 1 60
1 3 20
3 4 10
2 4 5
4 1 50
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
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

const int maxn = 1e6 + 5;
typedef vector<PII> VII;
VII G[maxn];
bool vis[maxn];
ll dis[maxn], ans;
int u[maxn], v[maxn], w[maxn];

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
    clr(vis, 0);
    clr(dis, 0x3f);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> >q;
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
    for (int i = 1; i < n; i++)
        ans += dis[i];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        ans = 0;
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            u[i]--, v[i]--;
            add_edge(u[i], v[i], w[i]);
        }
        Dijkstra(0, n);
        init(n);
        for (int i = 0; i < m; i++)
            add_edge(v[i], u[i], w[i]);
        Dijkstra(0, n);
        printf("%lld\n", ans);
    }
    return 0;
}
