#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

namespace Dijkstra
{
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};

const int N = 1 << 10;
vector<Edge> edges;
vector<int> G[N];
long long d[N][N];
bool done[N];
struct HeapNode
{
    long long d;
    int u;
    bool operator<(const HeapNode& rhs) const { return d > rhs.d; }
};
int n, m;
void init(int n)
{
    Dijkstra::n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
}

void AddEdge(int from, int to, int dist)
{
    edges.emplace_back(from, to, dist);
    Dijkstra::m = edges.size();
    G[from].push_back(m - 1);
}

void dijkstra(int s)
{
    long long* d = Dijkstra::d[s];
    for (int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    memset(done, false, sizeof(done));
    priority_queue<HeapNode> q;
    q.push({d[s], s});
    while (!q.empty())
    {
        auto x = q.top();
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
                q.push({d[e.to], e.to});
            }
        }
    }
}

} // namespace Dijkstra

using namespace Dijkstra;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    for (int i = 0; i < n; i++) dijkstra(i);
    int k;
    scanf("%d", &k);
    vector<int> u(k + 1);
    vector<long long> s(k + 1), t(k + 1);
    for (int i = 1; i <= k; i++) scanf("%lld%d%lld", &s[i], &u[i], &t[i]), --u[i];
    long long l = 0, r = INF, ans;
    while (l <= r)
    {
        long long mid = l + r >> 1;
        if ([&](long long now) {
                static long long dp[N];
                for (int i = 1; i <= k; i++) dp[i] = INF;
                for (int i = 1; i <= k; i++)
                {
                    long long mx = max(dp[i - 1], t[i]) + d[0][u[i]] - s[i];
                    long long cur = max(dp[i - 1], t[i]) + d[0][u[i]] * 2;
                    if (mx <= now) dp[i] = min(dp[i], cur);
                    long long prev = max(dp[i - 1], t[i]);
                    for (int j = i - 1; j; j--)
                    {
                        long long st = max(dp[j - 1], t[i]);
                        mx = max(st + d[0][u[j]] - s[j], mx + st - prev + d[0][u[j]] + d[u[j]][u[j + 1]] - d[0][u[j + 1]]);
                        cur += st - prev + d[0][u[j]] + d[u[j]][u[j + 1]] - d[0][u[j + 1]];
                        if (mx <= now) dp[i] = min(dp[i], cur);
                        prev = st;
                    }
                    if (dp[i] == INF) return true;
                }
                return false;
            }(mid))
            l = mid + 1;
        else
            r = mid - 1, ans = mid;
    }
    printf("%lld\n", ans);
}