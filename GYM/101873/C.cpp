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
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
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
const int maxn = 1 << 21;
struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    ll d[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        dbg(from, to, dist);
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
                    q.push({d[e.to], e.to});
                }
            }
        }
        for (int i = 0; i < n; i++) dbg(i, d[i]);
    }
} gao;

int main()
{
    int x;
    scanf("%d", &x);
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    gao.init((x + 1) * n * 2);
    auto getid = [&](int p, int t, int f) { return (p * (x + 1) + t) * 2 + f; };
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        for (int j = 0; j + t <= x; j++)
            gao.AddEdge(getid(u, j, 1), getid(v, j + t, 0), 0),
                gao.AddEdge(getid(v, j, 1), getid(u, j + t, 0), 0);
    }
    for (int i = 0, t, p; i < n; i++)
    {
        scanf("%d%d", &t, &p);
        for (int j = 0; j + t <= x; j++)
            gao.AddEdge(getid(i, j, 0), getid(i, j + t, 1), p),
                gao.AddEdge(getid(i, j, 1), getid(i, j, 0), 0);
    }
    gao.dijkstra(0);
    ll ans = gao.d[x * 2 + 1];
    if (ans == 1e18)
        puts("It is a trap.");
    else
        printf("%lld\n", ans);
    return 0;
}