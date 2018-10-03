#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ull Seed_Pool[] = {146527, 19260817};
const ull Mod_Pool[] = {1000000009, 998244353};
struct Hash
{
    ull SEED, MOD;

    vector<ull> p, h;
    Hash() {}
    Hash(const string& s, const int& seed_index = 0, const int& mod_index = 0)
    {
        SEED = Seed_Pool[seed_index];
        MOD = Mod_Pool[mod_index];
        int n = s.length();
        p.resize(n + 1), h.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * SEED % MOD;
        for (int i = 1; i <= n; i++) h[i] = (h[i - 1] * SEED % MOD + s[i - 1]) % MOD;
    }
    ull get(int l, int r) { return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD; }
    ull substr(int l, int m) { return get(l, l + m); }
};

const int N = 512;
char s[N];

const int INF = 0x3f3f3f3f;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

const int maxn = 1 << 9;
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.emplace_back(from, to, cap, 0, cost);
        edges.emplace_back(to, from, 0, 0, -cost);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BellmanFord(int s, int t, int& flow, ll& cost)
    {
        for (int i = 0; i < n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    int MincostMaxflow(int s, int t, ll& cost)
    {
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost))
            ;
        return flow;每年
    }
} gao;

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    Hash h(s);
    int m;
    scanf("%d", &m);
    gao.init(n + 3);
    int S = n + 1, T = n + 2;
    for (int i = 0, w; i < m; i++)
    {
        scanf("%s%d", s, &w);
        Hash hh(s);
        int len = strlen(s);
        ull t = hh.get(0, len);
        for (int i = 0; i + len - 1 < n; i++)
            if (h.substr(i, len) == t)
                gao.AddEdge(i, i + len, 1, -w);
    }
    int x;
    scanf("%d", &x);
    gao.AddEdge(S, 0, x, 0);
    gao.AddEdge(n, T, x, 0);
    for (int i = 0; i < n; i++) gao.AddEdge(i, i + 1, x, 0);
    ll cost;
    assert(gao.MincostMaxflow(S, T, cost) == x);
    printf("%lld\n", -cost);
    return 0;
}