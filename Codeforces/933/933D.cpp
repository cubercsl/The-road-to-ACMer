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

const int N = 1 << 18;

struct Edge
{
    int from, to;
    ll dist;
};

struct HeapNode
{
    ll d;
    int u;
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};

vector<Edge> edges;
vector<int> G[N];

bool vis[N];
ll d[N];

void add_edge(int from, int to, ll dist)
{
    edges.push_back({from, to, dist});
    G[from].push_back(edges.size() - 1);
}

void Dijkstra(int s, int n)
{
    priority_queue<HeapNode> q;
    for (int i = 0; i <= n; i++) d[i] = 1e18;
    d[s] = 0;
    clr(vis, 0);
    q.push({0, s});
    while (!q.empty())
    {
        HeapNode x = q.top();
        q.pop();
        int u = x.u;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto& id : G[u])
        {
            Edge& e = edges[id];
            if (!vis[e.to] && d[e.to] > d[u] + e.dist)
            {
                d[e.to] = d[u] + e.dist;
                q.push({d[e.to], e.to});
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
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        static int u, v;
        static ll w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(u, v, w * 2);
        add_edge(v, u, w * 2);
    }
    for (int i = 1; i <= n; i++)
    {
        static ll a;
        scanf("%lld", &a);
        add_edge(0, i, a);
    }
    Dijkstra(0, n);
    for (int i = 1; i <= n; i++) printf("%lld%c", d[i], " \n"[i == n]);
    return 0;
}