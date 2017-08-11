// Marriage Match IV, HDU3416

/*Sample Input
3
7 8
1 2 1
1 3 1
2 4 1
3 4 1
4 5 1
4 6 1
5 7 1
6 7 1
1 7

6 7
1 2 1
2 3 1
1 3 3
3 4 1
3 5 1
4 6 1
5 6 1
1 6

2 2
1 2 1
1 2 2
1 2
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

const int maxn = 1e5 + 5;
typedef vector<PII> VII;
VII G[maxn];
bool vis[maxn];
int u[maxn], v[maxn], d[maxn];
int d1[maxn], d2[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int d)
{
    G[u].pb(mp(d, v));
}

void Dijk(int s, int n, int* dis)
{
    for (int i = 0; i < n; i++)
        dis[i] = INF;
    clr(vis, 0);
    priority_queue <PII, VII, greater<PII> > q;
    dis[s] = 0;
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
}

struct edge
{
    int to, cap, rev;
    edge(int to, int cap, int rev): to(to), cap(cap), rev(rev) {}
};

struct Dinic
{
    vector <edge> G[maxn];
    int level[maxn];
    int iter[maxn];

    void init(int n)
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
    }

    void add_edge (int u, int v, int c)
    {
        G[u].pb(edge(v, c, G[v].size()));
        G[v].pb(edge(u, 0, G[u].size() - 1));
    }

    void bfs(int s)
    {
        clr(level, -1);
        queue <int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i = 0; i < G[v].size(); i++)
            {
                edge& e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f)
    {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to])
            {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {
            bfs(s);
            if (level[t] < 0) return flow;
            clr(iter, 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0)
                flow += f;
        }
    }
} ans;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, a, b;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &d[i]);
            if (u[i] == v[i]) continue;
            add_edge(--v[i], --u[i], d[i]);
        }
        scanf("%d%d", &a, &b);
        Dijk(--b, n, d2);
        init(n);
        for (int i = 0; i < m; i++)
            add_edge(u[i], v[i], d[i]);
        Dijk(--a, n, d1);
        ans.init(n);
        for (int u = 0; u < n; u++)
        {
            for (int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i].Y;
                int d = G[u][i].X;
                if (d1[u] + d + d2[v] == d1[b])
                    ans.add_edge(u, v, 1);
            }
        }
        printf("%d\n", ans.max_flow(a, b));
    }
    return 0;
}
