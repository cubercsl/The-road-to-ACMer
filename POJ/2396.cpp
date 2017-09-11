#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
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

const int maxn = 505;
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

int in[maxn], up[maxn][maxn], down[maxn][maxn];
int n, m, s, t, S, T;
bool build()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (up[i][j] < down[i][j])
                return false;
            else
            {
                ans.AddEdge(i, j + n, up[i][j] - down[i][j]);
                in[i] -= down[i][j];
                in[j + n] += down[i][j];
            }
    return true;
}

bool solve()
{
    int sum = 0;
    for (int i = 1; i <= t; i++)
    {
        if (in[i] > 0)
            ans.AddEdge(S, i, in[i]), sum += in[i];
        else if (in[i] < 0)
            ans.AddEdge(i, T, -in[i]);
    }
    if (sum != ans.Maxflow(S, T)) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int k, x, y, z;
        int rsum = 0, csum = 0;
        char ch[2];
        scanf("%d%d", &n, &m);
        s = n + m + 1, t = s + 1, S = t + 1, T = S + 1;
        ans.init(T + 1);
        clr(in, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                up[i][j] = 1000, down[i][j] = -1000;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            in[s] -= x;
            in[i] += x;
            //ans.AddEdge(s, i, 0);
            rsum += x;
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &x);
            in[n + i] -= x;
            in[t] += x;
            //ans.AddEdge(i, t, 0);
            csum += x;
        }
        scanf("%d", &k);
        while (k--)
        {
            scanf("%d%d%s%d", &x, &y, ch, &z);
            int rs = x ? x : 1, re = x ? x : n;
            int cs = y ? y : 1, ce = y ? y : m;
            for (int i = rs; i <= re; i++)
                for (int j = cs; j <= ce; j++)
                    if (ch[0] == '=')
                        up[i][j] = down[i][j] = z;
                    else if (ch[0] == '<')
                        up[i][j] = min(up[i][j], z - 1);
                    else if (ch[0] == '>')
                        down[i][j] = max(down[i][j], z + 1);
        }
        ans.AddEdge(t, s, INF);
        int cur = ans.edges.size();
        if (rsum == csum && build() && solve())
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++, cur += 2)
                    printf("%d%c", ans.edges[cur].flow + down[i][j], j != m ? ' ' : '\n');
        else
            puts("IMPOSSIBLE");
        puts("");
    }
    return 0;
}
