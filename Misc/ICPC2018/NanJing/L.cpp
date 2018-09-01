#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Edge
{
    int from, to;
    ll dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};

struct HeapNode
{
    ll d;
    int k, u;
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};
const int maxn = 1 << 17;
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[maxn]; // 每个节点出发的边编号（从0开始编号）
    bool done[maxn][12]; // 是否已永久标号
    ll d[maxn][12];      // s到各点的距离
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear(); // 清空邻接表
        edges.clear();                            // 清空边表
    }
    void AddEdge(int from, int to, int dist)
    { // 如果是无向图，每条无向边需调用两次AddEdge
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s, int k)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++) d[i][j] = 1e18;
        d[s][0] = 0;
        memset(done, 0, sizeof(done));
        q.push({0, 0, s});
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            int t = x.k;
            if (done[u][t]) continue;
            done[u][t] = true;
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (d[e.to][t] > d[u][t] + e.dist)
                {
                    d[e.to][t] = d[u][t] + e.dist;
                    q.push({d[e.to][t], t, e.to});
                }
                if (t + 1 <= k)
                {
                    if (d[e.to][t + 1] > d[u][t])
                    {
                        d[e.to][t + 1] = d[u][t];
                        q.push({d[e.to][t + 1], t + 1, e.to});
                    }
                }
            }
        }
    }
} ans;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        ans.init(n);
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            ans.AddEdge(u, v, w);
        }
        ans.dijkstra(0, k);
        ll ret = 1e18;
        for (int i = 0; i <= k; i++)
            ret = min(ret, ans.d[n - 1][i]);
        printf("%lld\n", ret);
    }
}