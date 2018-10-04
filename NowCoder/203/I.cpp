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
 
typedef long long ll;
 
struct HeapNode
{
    ll d;
    int u, s;
    bool operator<(const HeapNode& rhs) const { return d > rhs.d; }
};
 
struct Edge
{
    int from, to, cost;
    Edge() {}
    Edge(int u, int v, int w) : from(u), to(v), cost(w) {}
};
 
const int N = 1 << 18;
vector<Edge> edges;
vector<int> G[N];
 
ll d[N], ans[N];
int vis[N];
 
void addedge(int from, int to, int cost)
{
    edges.emplace_back(from, to, cost);
    G[from].push_back(edges.size() - 1);
}
 
int main()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    vector<int> c(p);
    for (int i = 0; i < p; i++) scanf("%d", &c[i]);
 
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    priority_queue<HeapNode> q;
    for (int i = 1; i <= n; i++) d[i] = 1e18, ans[i] = 1e18;
    for (auto& u : c)
    {
        d[u] = 0;
        q.push({d[u], u, u});
    }
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        int u = x.u, s = x.s;
        dbg(u);
        if (vis[u])
        {
            dbg(u, s, vis[u]);
            if (s == vis[u]) continue;
            ans[s] = min(ans[s], x.d + d[u]);
            dbg(x.d + d[u]);
            continue;
        }
        vis[u] = s;
        for (auto& id : G[u])
        {
            auto& e = edges[id];
            int w = e.cost;
            if (d[e.to] > d[u] + w)
            {
                d[e.to] = d[u] + w;
                q.push({d[e.to], e.to, x.s});
            }
            else if (e.to != x.s)
                q.push({d[u] + w, e.to, x.s});
        }
    }
    for (int i = 0; i < p; i++) printf("%lld%c", ans[c[i]], " \n"[i == p - 1]);
}
/*
5 6 3
2 4 5
1 2 4
1 3 1
1 4 1
1 5 4
2 3 1
3 4 3
*/