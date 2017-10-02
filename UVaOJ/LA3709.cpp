// Hard Life, LA3709

/*Sample Input
5 6
1 5
5 4
4 2
2 5
1 2
3 1
4 0
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

const int maxn = 1110;
struct Edge
{
    int from, to;
    double cap, flow;
    Edge(int u, int v, double c, double f) : from(u), to(v), cap(c), flow(f) {}
};
struct ISAP
{
    int n, m, s, t;      //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<Edge> edges;  //边表。edges[e]和edges[e^1]互为反向弧
    vector<int> G[maxn]; //邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];      //BFS使用
    int d[maxn];         //起点到i的距离
    int cur[maxn];       //当前弧下标
    int p[maxn];         //可增广路上的一条弧
    int num[maxn];       //距离标号计数
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, double cap)
    {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));
        int m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    double Augumemt()
    {
        int x = t;
        double a = INF;
        while (x != s)
        {
            Edge& e = edges[p[x]];
            a = min(a, e.cap - e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while (x != s)
        {
            edges[p[x]].flow += a;
            edges[p[x] ^ 1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }
    void BFS()
    {
        clr(vis, 0);
        clr(d, 0);
        queue<int> q;
        q.push(t);
        d[t] = 0;
        vis[t] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            int len = G[x].size();
            for (int i = 0; i < len; i++)
            {
                Edge& e = edges[G[x][i]];
                if (!vis[e.from] && e.cap > e.flow)
                {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    q.push(e.from);
                }
            }
        }
    }
    double Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        double flow = 0;
        BFS();
        clr(num, 0);
        for (int i = 0; i < n; i++) num[d[i]]++;
        int x = s;
        clr(cur, 0);
        while (d[s] < n)
        {
            if (x == t)
            {
                flow += Augumemt();
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
                if (e.cap > e.flow && d[x] == d[e.to] + 1)
                {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;
                }
            }
            if (!ok) //Retreat
            {
                int m = n - 1;
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge& e = edges[G[x][i]];
                    if (e.cap > e.flow)
                        m = min(m, d[e.to]);
                }
                if (--num[d[x]] == 0) break; //gap优化
                num[d[x] = m + 1]++;
                cur[x] = 0;
                if (x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }
};
ISAP isap;
int n, m;
PII a[maxn];

void build(double mid, int s, int t)
{
    isap.init(t + 1);
    for (int i = 1; i <= m; i++)
    {
        isap.addedge(s, n + i, 1.0);
        isap.addedge(n + i, a[i].X, INF);
        isap.addedge(n + i, a[i].Y, INF);
    }
    for (int i = 1; i <= n; i++) isap.addedge(i, t, mid);
}

bool vis[maxn];
void dfs(int u, int& cnt)
{
    vis[u] = true;
    if (u >= 1 && u <= n) cnt++;
    for (auto& t : isap.G[u])
    {
        Edge& e = isap.edges[t];
        if (!vis[e.to] && e.cap - e.flow > eps) dfs(e.to, cnt);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    bool flag = 0;
    while (~scanf("%d%d", &n, &m))
    {
        flag ? puts("") : flag = 1;
        if (!m)
        {
            printf("1\n1\n");
            continue;
        }
        for (int i = 1; i <= m; i++)
            scanf("%d%d", &a[i].X, &a[i].Y);
        int s = 0, t = n + m + 1;
        double l = 0, r = m;
        while (r - l >= 1.0 / n / n)
        {
            double mid = (l + r) / 2;
            build(mid, s, t);
            double ans = isap.Maxflow(s, t);
            if (1.0 * m - ans < eps)
                r = mid;
            else
                l = mid;
        }
        build(l, s, t);
        isap.Maxflow(s, t);
        clr(vis, 0);
        int cnt = 0;
        dfs(s, cnt);
        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++)
            if (vis[i]) printf("%d\n", i);
    }
    return 0;
}
