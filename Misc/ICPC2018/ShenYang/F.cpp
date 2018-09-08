#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f)
        : from(u), to(v), cap(c), flow(f) {}
};

const int maxn = 4096;
const int INF = 0x3f3f3f3f;
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
    int DFS(int x, int a)
    {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        {
            //从上次考虑的弧
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
    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} gao;

int main()
{
    int n, m, k, kase = 0;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        int l, r;
        scanf("%d%d", &l, &r);
        gao.init(n + m + 4);
        int s = 0, t = n + m + 1;
        int S = n + m + 2, T = n + m + 3;
        gao.AddEdge(t, s, INF);
        gao.AddEdge(s, T, l * n);
        gao.AddEdge(S, t, l * m);
        for (int i = 1; i <= n; i++) gao.AddEdge(s, i, r - l), gao.AddEdge(S, i, l);
        for (int i = 1; i <= m; i++) gao.AddEdge(n + i, t, r - l), gao.AddEdge(n + i, T, l);
        for (int i = 0, u, v; i < k; i++)
        {
            scanf("%d%d", &u, &v);
            gao.AddEdge(u, n + v, 1);
        }
        int flow = gao.Maxflow(S, T);
        printf("Case %d: ", ++kase);
        if (flow == (n + m) * l)
            puts("Yes");
        else
            puts("No");
    }
}