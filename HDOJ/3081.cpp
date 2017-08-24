// Marriage Match II, HDU3081

/*Sample Input
1
4 5 2
1 1
2 3
3 2
4 2
4 4
1 4
2 3
*/

#include <bits/stdc++.h>
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

const int maxn = 205;
const int maxm = 105;
bool C[maxm][maxm], F[maxm][maxm];
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

void floyd(int n)
{
    for (int i = 0; i < n; i++)
        F[i][i] = true;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                F[i][j] |= F[i][k] & F[k][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (F[i][j])
                for (int k = 0; k < n; k++)
                    C[i][k] |= C[j][k];
}

bool ok(int mid, int n)
{
    int s = n << 1;
    int t = n << 1 | 1;
    ans.init(t + 1);
    for (int i = 0; i < n; i++)
    {
        ans.AddEdge(s, i, mid);
        ans.AddEdge(n + i, t, mid);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (C[i][j])
                ans.AddEdge(i, n + j, 1);
    return ans.Maxflow(s, t) == mid * n;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t, n, m, f, u, v;
    cin >> t;
    while (t--)
    {
        clr(C, 0);
        clr(F, 0);
        cin >> n >> m >> f;
        while (m--)
        {
            cin >> u >> v;
            C[u - 1][v - 1] = true;
        }
        while (f--)
        {
            cin >> u >> v;
            F[u - 1][v - 1] = true;
            F[v - 1][u - 1] = true;
        }
        floyd(n);
        int L = 0, R = n, res;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (ok(mid, n))
                res = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}
