// Power Network, POJ1459

/*Sample Input
2 1 1 2 (0,1)20 (1,0)10 (0)15 (1)20
7 2 3 13 (0,0)1 (0,1)2 (0,2)5 (1,0)1 (1,2)8 (2,3)1 (2,4)7
         (3,5)2 (3,6)5 (4,2)7 (4,3)5 (4,5)1 (6,0)5
         (0)5 (1)2 (3)2 (4)1 (5)4
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
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

const int maxn = 105;

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
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, p, c, m;
    while (~scanf("%d%d%d%d", &n, &p, &c, &m))
    {
        ans.init(n + 2);
        int s = n , t = s + 1;
        int u, v, w;
        char ch;
        while (m--)
        {
            while (ch = getchar(), ch != '(');
            scanf("%d,%d)%d", &u, &v, &w);
            ans.AddEdge(u, v, w);
        }
        while (p--)
        {
            while (ch = getchar(), ch != '(');
            scanf("%d)%d", &u, &w);
            ans.AddEdge(s, u, w);
        }
        while (c--)
        {
            while (ch = getchar(), ch != '(');
            scanf("%d)%d", &v, &w);
            ans.AddEdge(v, t, w);
        }
        printf("%d\n", ans.Maxflow(s, t));
    }
    return 0;
}
