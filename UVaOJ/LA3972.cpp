// March of the Penguins,NWERC 2007 ,LA3972

/*Sample Input
2
5 3.5
1 1 1 1
2 3 0 1
3 5 1 1
5 1 1 1
5 4 0 1
3 1.1
-1 0 5 10
0 0 3 9
2 0 1 1
*/

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
const double eps = 1e-6;

const int maxn = 2e5 + 5;
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
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
} ans;

struct Node
{
    int x, y, n, m;
    Node() {}
    Node(int X, int Y, int N, int M) : x(X), y(Y), n(N), m(M) {}
};

Node node[100];

inline double dis2(const Node& a, const Node& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool can[100][100];

bool solve(const int& id, const int& N, const int& tot)
{
    // printf("solve %d\n", N);
    int s = N << 1, t = s + 1;
    ans.init(t + 1);
    for (int i = 0; i < N; i++)
    {
        Node& tmp = node[i];
        ans.AddEdge(s, i, tmp.n);
        ans.AddEdge(i, N + i, tmp.m);
        for (int j = i + 1; j < N; j++)
            if (can[i][j])
            {
                ans.AddEdge(i + N, j, INF);
                ans.AddEdge(j + N, i, INF);
            }
    }
    ans.AddEdge(id, t, INF);
    int flow = ans.Maxflow(s, t);
    // printf("flow = %d, tot = %d\n", flow, tot);
    return flow == tot;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        double D;
        scanf("%d%lf", &N, &D);
        int x, y, n, m, tot = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d%d%d", &x, &y, &n, &m);
            node[i] = Node(x, y, n, m);
            tot += n;
        }
        clr(can, 0);
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (dis2(node[i], node[j]) <= D * D) can[i][j] = can[j][i] = 1;
        bool flag = 0;
        for (int i = 0; i < N; i++)
            if (solve(i, N, tot))
            {
                if (flag) putchar(' ');
                flag = 1;
                printf("%d", i);
            }
        puts(flag ? "" : "-1");
    }
    return 0;
}
