// Inspection, LA4597

/*Sample Input
8
1 3
1 7
2 4 5
1 8
1 8
0
2 6 5
0
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

const int maxn = 105;
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

int in[maxn], out[maxn];
vector<int> G[maxn];
bool check(int flow, const int& n)
{
    int s = 0, t = n + 1, S = n + 2, T = n + 3;
    ans.init(T + 1);
    int sum = 0;
    for (int u = 1; u <= n; u++)
    {
        ans.AddEdge(s, u, INF);
        ans.AddEdge(u, t, INF);
        for (auto& v : G[u])
            ans.AddEdge(u, v, INF);
    }
    ans.AddEdge(t, s, flow);
    for (int u = 1; u <= n; u++)
    {
        int tmp = in[u] - out[u];
        if (tmp > 0)
            ans.AddEdge(S, u, tmp), sum += tmp;
        else if (tmp < 0)
            ans.AddEdge(u, T, -tmp);
    }
    return sum == ans.Maxflow(S, T);
}

int cap[maxn][maxn];
int ANS[maxn];
bool dfs(int u, int dep, const int& t)
{
    ANS[dep] = u;
    if (u == t)
    {
        for (int i = 1; i < dep; i++)
            printf("%d%c", ANS[i], i == dep - 1 ? '\n' : ' ');
        return true;
    }
    for (int v = 1; v <= t; v++)
    {
        if (cap[u][v])
        {
            cap[u][v]--;
            if (dfs(v, dep + 1, t))
                return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d", &n))
    {
        clr(in, 0), clr(out, 0), clr(cap, 0);
        for (int u = 1; u <= n; u++)
        {
            G[u].clear();
            scanf("%d", &m);
            while (m--)
            {
                int v;
                scanf("%d", &v);
                G[u].pb(v);
                cap[u][v] = 1;
                out[u]++, in[v]++;
            }
        }
        int L = 0, R = INF, ret;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (check(mid, n))
                R = mid - 1, ret = mid;
            else
                L = mid + 1;
        }
        printf("%d\n", ret);
        check(ret, n);
        int s = 0, t = n + 1;
        for (int u = 0; u <= n; u++)
        {
            for (auto& x : ans.G[u])
            {
                Edge& e = ans.edges[x];
                int v = e.to;
                if (u != s && v != t && cap[u][v] == 0) continue;
                if (v > n + 1) continue;
                int tmp = e.flow + 1 - (u == s || v == t);
                if (tmp <= 0) continue;
                cap[u][v] = tmp;
                // printf("%d %d = %d\n", u, v, tmp);
            }
        }
        for (int u = 1; u <= n; u++)
            while (cap[s][u])
            {
                // printf("u = %d\n", u);
                cap[s][u]--;
                dfs(u, 1, t);
            }
    }
    return 0;
}
