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
const double eps = 1e-6;

const int maxn = 1e5 + 5;
typedef vector<PII> VII;
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
void Dijkstra(int n)
{
    clr(vis, 0);
    priority_queue<PII, VII, greater<PII> > q;
    for (int i = 0; i < n; i++)
        q.push(mp(dis[i], i));
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
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &dis[i]);
        while (m--)
        {
            int u, v, w1, w2;
            scanf("%d%d%d%d", &u, &v, &w1, &w2);
            add_edge(u, v, w1);
            add_edge(v, u, w2);
        }
        Dijkstra(n);
        int ans = 0;
        for (int i = 1; i < n; i++)
            if (dis[ans] < dis[i])
                ans = i;
        printf("Scenario #%d:\n%d\n\n", ++kase, ans);
    }

    return 0;
}
