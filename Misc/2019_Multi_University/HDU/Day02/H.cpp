#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...)
#endif
const int maxn = 20005;

typedef long long ll;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to;
    long long cap, flow;
    Edge(int u, int v, int c, int f)
        : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic
{
    int n, m, s, t;      //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<Edge> edges;  //边表。edge[e]和edge[e^1]互为反向弧
    vector<int> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    bool vis[maxn];      //BFS使用
    int d[maxn];         //从起点到i的距离
    int cur[maxn];       //当前弧下标
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
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
    int DFS(int x, long long a)
    {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        { //从上次考虑的弧
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
    long long Maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        long long flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} gao;

const int N = 512;
long long sum[N][2];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {

        gao.init(n + 2);
        int s = 0, t = n + 1;
        long long res = 0;
        for (int i = 1; i <= n; i++) sum[i][0] = sum[i][1] = 0;
        for (int i = 1, u, v, a, b, c; i <= m; i++)
        {
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &c);
            res += a + b + c;
            sum[u][0] += b + c;
            sum[v][0] += b + c;
            sum[u][1] += a + b;
            sum[v][1] += a + b;
            gao.AddEdge(u, v, a + c - 2 * b);
            gao.AddEdge(v, u, a + c - 2 * b);
        }
        for (int i = 1; i <= n; i++)
        {
            gao.AddEdge(s, i, sum[i][0]);
            gao.AddEdge(i, t, sum[i][1]);
        }
        printf("%lld\n", res - gao.Maxflow(s, t) / 2);
    }
}