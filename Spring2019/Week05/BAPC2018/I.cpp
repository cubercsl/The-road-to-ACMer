#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
typedef long long ll;

struct Dijkstra
{
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
    void AddEdge(int from, int to, ll dist)
    {
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
    }
} osp;

int p[maxn];
int S[maxn], C[maxn];
ll d[10][maxn];
const ll INF = 1e18;

struct Dinic
{
    struct Edge
    {
        int from, to;
        ll cap, flow;
        Edge(int u, int v, ll c, ll f)
            : from(u), to(v), cap(c), flow(f) {}
    };
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, ll cap)
    {
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, 0, 0);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    ll DFS(int x, ll a)
    {
        if (x == t || a == 0) return a;
        ll flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    ll Maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        ll flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} gao;

ll sum;

bool check(ll x, int n, int s)
{
    int tot = n + (1 << s) + s + 2;
    int S = n + (1 << s) + s;
    int T = S + 1;
    gao.init(tot);
    for (int i = 0; i < n; i++) gao.AddEdge(S, i, p[i]);
    for (int i = 0; i < s; i++) gao.AddEdge(n + (1 << s) + i, T, C[i]);
    for (int i = 0; i < (1 << s); i++)
        for (int j = 0; j < s; j++)
            if (i >> j & 1) gao.AddEdge(n + i, n + (1 << s) + j, INF);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = 0; j < s; j++)
            if (d[j][i] <= x) mask |= (1 << j);
        gao.AddEdge(i, n + mask, INF);
    }
    ll flow = gao.Maxflow(S, T);
    return flow == sum;
}

int main()
{
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]), sum += p[i];
    osp.init(n);
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        osp.AddEdge(u, v, w);
        osp.AddEdge(v, u, w);
    }

    for (int i = 0; i < s; i++)
    {
        scanf("%d%d", &S[i], &C[i]);
        --S[i];
        osp.dijkstra(S[i]);
        for (int j = 0; j < n; j++) d[i][j] = osp.d[j];
    }

    ll l = 0, r = 1e15;
    ll ans;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid, n, s))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld\n", ans);
}