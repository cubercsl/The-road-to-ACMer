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

const int maxn = 50005;
int par[maxn], dis[maxn], ans[maxn];
vector<PII> G[maxn];
vector<int> query[maxn], num[maxn];
bool vis[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        G[i].clear();
        query[i].clear();
        num[i].clear();
        par[i] = i;
        dis[i] = 0;
        vis[i] = 0;
    }
}

inline void add_edge(int u, int v, int w)
{
    G[u].pb(mp(v, w));
}


inline int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

inline void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
}

void tarjan(int u, int val)
{
    vis[u] = 1;
    dis[u] = val;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].X;
        int w = G[u][i].Y;
        if (vis[v]) continue;
        tarjan(v, val + w);
        unite(u, v);
    }
    for (int i = 0; i < query[u].size(); i++)
    {
        int v = query[u][i];
        if (!vis[v]) continue;
        ans[num[u][i]] = dis[u] + dis[v] - 2 * dis[find(v)];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int _;
    for (scanf("%d", &_); _; _--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        init(n);
        int u, v, w;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &u, &v);
            query[u].pb(v);
            query[v].pb(u);
            num[u].pb(i);
            num[v].pb(i);
        }
        tarjan(1, 0);
        for (int i = 0; i < q; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
