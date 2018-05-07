#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const ld eps = 1e-12;

struct Edge
{
    int from, to;
    ld cap, flow;
    Edge(int u, int v, ld c, ld f) : from(u), to(v), cap(c), flow(f) {}
};

const int maxn = 1 << 17;
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
    void AddEdge(int from, int to, ld cap)
    {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    bool BFS()
    {
        clr(vis, 0);
        clr(d, 0);
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
                if (!vis[e.to] && e.cap > e.flow + eps)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    ld DFS(int x, ld a)
    {
        if (x == t || a < eps) return a;
        ld flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        {
            //从上次考虑的弧
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > eps)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a < eps) break;
            }
        }
        return flow;
    }
    ld Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ld flow = 0;
        while (BFS())
        {
            clr(cur, 0);
            flow += DFS(s, INF);
        }
        return flow;
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    ld l = 0, r = n * n;
    while (l + eps < r)
    {
        ld m = (l + r) / 2;
        gao.init(n + n * n + 2);
        int s = n + n * n, t = s + 1;
        int x = 0;
        for (int i = 0; i < n; i++) gao.AddEdge(i, t, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[i] % a[j] == 0 || a[j] % a[i] == 0)
                    gao.AddEdge(s, n + x, 1), gao.AddEdge(n + x, i, INF), gao.AddEdge(n + x, j, INF), x++;
        ld ret = x - gao.Maxflow(s, t);
        if (ret > eps)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(10) << l << endl;
    return 0;
}