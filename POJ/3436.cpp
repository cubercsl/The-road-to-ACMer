// ACM Computer Factory, POJ3436

/*Sample Input
3 4
15  0 0 0  0 1 0
10  0 0 0  0 1 1
30  0 1 2  1 1 1
3   0 2 1  1 1 1
3 5
5   0 0 0  0 1 0
100 0 1 0  1 0 1
3   0 1 0  1 1 0
1   1 0 1  1 1 0
300 1 1 2  1 1 1
2 2
100  0 0  1 0
200  0 1  1 1
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 55;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;         //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<Edge> edges;     //边表。edge[e]和edge[e^1]互为反向弧
    vector<int> G[maxn];    //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    bool vis[maxn];         //BFS使用
    int d[maxn];            //从起点到i的距离
    int cur[maxn];          //当前弧下标
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
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
            clr(cur, 0);
            flow += DFS(s, INF);
        }
        return flow;
    }
    void print(int s, int t, int n)
    {
        int mf = Maxflow(s, t);
        vector <Edge> vec;
        for (int i = 0; i < edges.size(); i++)
        {
            Edge& e = edges[i];
            if (e.flow <= 0 || e.from == s || e.to == t || e.to - e.from == n) continue;
            int u = e.from > n ? e.from - n : e.from;
            int v = e.to;
            vec.pb(Edge(u, v, 0, e.flow));
        }
        int m = vec.size();
        printf("%d %d\n", mf, m);
        for (int i = 0; i < vec.size(); i++)
        {
            Edge& e = vec[i];
            printf("%d %d %d\n", e.from, e.to, e.flow);
        }
    }
} ans;

struct node
{
    int p, in[10], out[10];
    bool _in, _out;
    void init(int p)
    {
        this->p = p;
        for (int i = 0; i < p; i++)
            scanf("%d", in + i);
        _in = in1();
        for (int i = 0; i < p; i++)
            scanf("%d", out + i);
        _out = out0();
    }
    bool in1()
    {
        for (int i = 0; i < p; i++)
            if (in[i] == 1)
                return true;
        return false;
    }
    bool out0()
    {
        for (int i = 0; i < p; i++)
            if (out[i] == 0)
                return true;
        return false;
    }
} a[maxn];

inline bool judge(node a, node b)
{
    int n = a.p;
    for (int i = 0; i < n; i++)
        if (a.out[i] + b.in[i] == 1)
            return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int p, n;

    while (~scanf("%d%d", &p, &n))
    {
        int s = 0, t = n << 1 | 1;
        ans.init(t + 1);
        for (int i = 1; i <= n; i++)
        {
            int w;
            scanf("%d", &w);
            ans.AddEdge(i, n + i, w);
            a[i].init(p);
            if (!a[i]._in) ans.AddEdge(s, i, INF);
            if (!a[i]._out) ans.AddEdge(n + i, t, INF);
            for (int j = 1; j < i; j++)
            {
                if (a[j]._in && a[i]._out && judge(a[i], a[j]))
                    ans.AddEdge(i + n, j, INF);
                if (a[i]._in && a[j]._out && judge(a[j], a[i]))
                    ans.AddEdge(j + n, i, INF);
            }
        }
        ans.print(s, t, n);
    }
    return 0;
}
