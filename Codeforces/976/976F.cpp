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

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

const int maxn = 1 << 12;
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
    vector<int> get_answer(int k, int n, int m)
    {
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            for (auto& id : G[i])
            {
                Edge& e = edges[id];
                if (e.to == 0 || e.to == n + m + 1) continue;
                if (e.cap == e.flow) continue;
                ans.push_back((id >> 1) + 1);
            }
        }
        if (k)
        {
            for (auto& id : G[s]) edges[id].cap++;
            for (auto& id : G[t]) edges[id ^ 1].cap++;
        }
        return ans;
    }

} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> deg(n + m + 1);
    deg[0] = INF;
    gao.init(n + m + 2);
    int s = 0, t = n + m + 1;
    while (q--)
    {
        static int u, v;
        cin >> u >> v;
        gao.AddEdge(u, n + v, 1);
        ++deg[u], ++deg[n + v];
    }
    int k = *min_element(deg.begin(), deg.end());
    for (int i = 1; i <= n; i++) gao.AddEdge(s, i, deg[i] - k);
    for (int i = 1; i <= m; i++) gao.AddEdge(n + i, t, deg[n + i] - k);
    vector<vector<int> > ans(k + 1);
    for (int i = k; ~i; i--)
    {
        int flow = gao.Maxflow(s, t);
        ans[i] = gao.get_answer(i, n, m);
    }
    for (int i = 0; i <= k; i++)
    {
        cout << ans[i].size();
        for (auto& t : ans[i]) cout << " " << t;
        cout << endl;
    }
    return 0;
}
