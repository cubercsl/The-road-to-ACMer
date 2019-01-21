#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

typedef long long ll;
struct Edge
{
    int from, to;
    ll dist;
    Edge() {}
    Edge(int u, int v, ll d) : from(u), to(v), dist(d) {}
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
const int maxn = 1 << 18;
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[maxn]; // 每个节点出发的边编号（从0开始编号）
    bool done[maxn];     // 是否已永久标号
    ll d[maxn];         // s到各点的距离
    // int p[maxn];         // 最短路中的一条边
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear(); // 清空邻接表
        edges.clear();                            // 清空边表
    }
    void AddEdge(int from, int to, ll dist)
    { // 如果是无向图，每条无向边需调用两次AddEdge
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++) d[i] = 1e18;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        q.push({0, s});
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    // p[e.to] = id;
                    q.push({d[e.to], e.to});
                }
            }
        }
    }
} solver;

int h[maxn];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    solver.init(n * 2);
    while (m--)
    {
        static int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x, --y;
        solver.AddEdge(x << 1 | 1, y << 1, z);
        solver.AddEdge(y << 1 | 1, x << 1, z);
    }
    solver.AddEdge(0, 1, 0);
    for (int i = 1; i < n; i++)
    {
        ll d = max(h[i] - (h[0] + k), 0);
        dbg(d);
        solver.AddEdge(i << 1, i << 1 | 1, d * d);
    }
    solver.dijkstra(0);
    printf("%lld\n", solver.d[(n - 1) << 1 | 1]);
    return 0;
}