// Duopoly, Hangzhou 2005, LA3487

/*Sample Input
2
3
45 1
51 2
62 3
4
54 1
15 2
33 3
2 4 5
5
20 1
18 2
23 4
54 3 5 6
17 7
4
36 1 2 3
28 5
47 4 7
16 6
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

const int maxn = 310000;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    int a[3005], b[3005];
    vector<int> A[3005], B[3005];
    scanf("%d", &T);
    while (T--)
    {
        int n, m, tmp, sum = 0;
        int s, t = 0;
        char c;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            A[i].clear();
            scanf("%d", a + i);
            sum += a[i];
            while ((c = getchar()) != '\n')
            {
                scanf("%d", &tmp);
                t = max(t, tmp);
                A[i].pb(tmp);
            }
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            B[i].clear();
            scanf("%d", b + i);
            sum += b[i];
            while ((c = getchar()) != '\n')
            {
                scanf("%d", &tmp);
                t = max(t, tmp);
                B[i].pb(tmp);
            }
        }
        s = n + m, t += n + m + 1;
        // printf("%d %d\n", s, t);
        ans.init(t + 1);
        for (int i = 0; i < n; i++)
        {
            ans.AddEdge(s, i, a[i]);
            for (auto& w : A[i])
                ans.AddEdge(i, n + m + w, INF);
        }
        for (int i = 0; i < m; i++)
        {
            ans.AddEdge(n + i, t, b[i]);
            for (auto& w : B[i])
                ans.AddEdge(n + m + w, n + i, INF);
        }
        int flow = ans.Maxflow(s, t);
        // printf("sum  = %d, flow = %d\n", sum, flow);
        printf("Case %d:\n%d\n", ++kase, sum - flow);
        T ? puts("") : 0;
    }
    return 0;
}
