#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 52520;
ll d[maxn], w[maxn];
int u[maxn], v[maxn];
ll pre[maxn];
typedef pair<ll, int> Edge;
vector<Edge> G[maxn];

inline void addedge(int u, int v, ll w)
{
    G[u].pb(mp(w, v));
    G[v].pb(mp(w, u));
}

ll dis[50][maxn];
bool vis[maxn];
void Dijkstra(int s, int n, int id)
{
    clr(vis, 0), clr(dis[id], 0x3f);
    dis[id][s] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge> > q;
    q.push(mp(dis[id][s], s));
    while (!q.empty())
    {
        Edge t = q.top();
        int x = t.Y;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].Y;
            ll w = G[x][i].X;
            if (!vis[y] && dis[id][y] > dis[id][x] + w)
            {
                dis[id][y] = dis[id][x] + w;
                q.push(mp(dis[id][y], y));
            }
        }
    }
}
int n, m, q;
inline ll getdis(int x, int y)
{
    if (x > y) swap(x, y);
    return min(pre[y - 1] - pre[x - 1], pre[n] - pre[y -1] + pre[x - 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", d + i);
        if (i != n)
            addedge(i, i + 1, d[i]);
        else
            addedge(n, 1, d[i]);
        pre[i] = pre[i - 1] + d[i];
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%lld", u + i, v + i, w + i);
        addedge(u[i], v[i], w[i]);
    }
    for (int i = 0; i < m; i++)
    {
        Dijkstra(u[i], n, i << 1);
        Dijkstra(v[i], n, i << 1 | 1);
    }
    scanf("%d", &q);
    while (q--)
    {
        static int x, y;
        scanf("%d%d", &x, &y);
        ll ans = getdis(x, y);
        // printf("ans = %lld\n", ans);
        for (int i = 0; i < m; i++)
        {
            ll tmp1 = getdis(x, u[i]) + dis[i << 1][y];
            ll tmp2 = getdis(x, v[i]) + dis[i << 1 | 1][y];
            // printf("%lld, %lld\n", tmp1, tmp2);
            ans = min(ans, min(tmp1, tmp2));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
