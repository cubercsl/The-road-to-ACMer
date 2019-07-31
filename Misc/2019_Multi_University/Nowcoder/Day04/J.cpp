#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to, cost;
    Edge(int u, int v, int c) : from(u), to(v), cost(c) {}
};

const int N = 1 << 10;
vector<Edge> edges;
vector<int> G[N];

void addedge(int from, int to, int cost)
{
    edges.emplace_back(from, to, cost);
    int m = edges.size();
    G[from].push_back(m - 1);
}

int d[N][N];
bool vis[N][N];

struct HeapNode
{
    int u, k;
    int d;
    HeapNode(int u, int k, int d) : u(u), k(k), d(d) {}
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};
int k;
void dijkstra(int s)
{
    memset(d, 0x3f, sizeof(d));
    d[s][0] = 0;
    vis[s][0] = 0;
    priority_queue<HeapNode> q;
    q.emplace(s, 0, d[s][0]);
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        int u = x.u;
        int k = x.k;
        if (vis[u][k]) continue;
        vis[u][k] = 1;
        for (auto& id : G[u])
        {
            auto e = edges[id];
            if (d[e.to][k] > d[e.from][k] + e.cost)
            {
                d[e.to][k] = d[e.from][k] + e.cost;
                q.emplace(e.to, k, d[e.to][k]);
            }
            if (k + 1 <= ::k && d[e.to][k + 1] > d[e.from][k])
            {
                d[e.to][k + 1] = d[e.from][k];
                q.emplace(e.to, k + 1, d[e.to][k + 1]);
            }
        }
    }
}

int main()
{
    int n, m, s, t, k;
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &k);
    ::k = k;
    for (int i = 0, u, v, c; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        addedge(u, v, c);
        addedge(v, u, c);
    }
    dijkstra(s);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; i++) ans = min(ans, d[t][i]);
    printf("%d\n", ans);
}