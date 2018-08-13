#include <bits/stdc++.h>
using namespace std;

struct HeapNode
{
    int d, u;
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};

struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
const int maxn = 1 << 20;
const int INF = 0x3f3f3f3f;
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[maxn]; // 每个节点出发的边编号（从0开始编号）
    bool done[maxn];     // 是否已永久标号
    int d[maxn];         // s到各点的距离
    int p[maxn];         // 最短路中的一条边
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear(); // 清空邻接表
        edges.clear();                            // 清空边表
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    int dijkstra(int s, int t)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0, p[s] = 0;
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
                int w = (p[u] != e.dist);
                // cerr << w << endl;
                if (d[e.to] > d[u] + w)
                {
                    d[e.to] = d[u] + w;
                    p[e.to] = e.dist;
                    q.push({d[e.to], e.to});
                }
            }
        }
        return d[t] == INF ? -1 : d[t];
    }
} gao;

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        gao.init(n + 1);
        for (int i = 0, u, v, c; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &c);
            gao.AddEdge(u, v, c);
            gao.AddEdge(v, u, c);
        }
        printf("%d\n", gao.dijkstra(1, n));
    }

    return 0;
}