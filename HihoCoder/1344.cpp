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

struct Edge
{
    int from, to, cost;
    Edge(int u, int v, int w) : from(u), to(v), cost(w) {}
};

const int N = 10005;

vector<Edge> edges;
vector<int> G[N];
inline void AddEdge(int u, int v, int w)
{
    edges.pb(Edge(u, v, w));
    edges.pb(Edge(v, u, w));
    int m = edges.size();
    G[u].pb(m - 2);
    G[v].pb(m - 1);
}

int d[25][N];
bool vis[N];
struct HeapNode
{
    int from, cost;
    HeapNode(int u, int w) : from(u), cost(w){};
    bool operator<(const HeapNode& rhs) const { return cost > rhs.cost; }
};

void Dijkstra(int s, int id)
{
    clr(vis, 0), clr(d[id], 0x3f);
    d[id][s] = 0;
    priority_queue<HeapNode> q;
    q.push(HeapNode(s, d[id][s]));
    while (!q.empty())
    {
        HeapNode t = q.top();
        q.pop();
        int u = t.from;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto& t : G[u])
        {
            Edge& e = edges[t];
            if (!vis[e.to] && d[id][e.to] > d[id][e.from] + e.cost)
            {
                d[id][e.to] = d[id][e.from] + e.cost;
                q.push(HeapNode(e.to, d[id][e.to]));
            }
        }
    }
}

struct Task
{
    int location, start, end, time, cost;
    Task(int l, int s, int e, int t, int c) : location(l), start(s), end(e), time(t), cost(c) {}
};

int dp[1 << 20][20];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, q;
    vector<Task> v;
    scanf("%d%d%d", &n, &m, &q);
    while (m--)
    {
        static int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        AddEdge(u, v, w);
    }
    for (int i = 0; i < q; i++)
    {
        static int l, s, e, t, c;
        scanf("%d%d%d%d%d", &l, &s, &e, &t, &c);
        v.pb(Task(l, s, e, t, c));
    }
    Dijkstra(1, q);
    for (int i = 0; i < q; i++) Dijkstra(v[i].location, i);
    clr(dp, 0x3f);
    for (int i = 0; i < q; i++)
    {
        Task& task = v[i];
        if (d[q][task.location] > task.end) continue;
        dp[1 << i][i] = max(d[q][task.location], task.start) + task.time;
    }
    int ans = 0;
    for (int i = 1; i < (1 << q); i++)
        for (int j = 0; j < q; j++)
            if (dp[i][j] != INF)
            {
                int cost = 0;
                for (int k = 0; k < q; k++)
                    if (i >> k & 1)
                        cost += v[k].cost;
                    else
                    {
                        Task& task = v[k];
                        if (dp[i][j] + d[j][task.location] > task.end) continue;
                        int tmp = max(dp[i][j] + d[j][task.location], task.start) + task.time;
                        dp[i | (1 << k)][k] = min(tmp, dp[i | (1 << k)][k]);
                    }
                ans = max(cost, ans);
            }
    printf("%d\n", ans);
    return 0;
}
