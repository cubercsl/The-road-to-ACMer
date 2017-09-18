// Objective: Berlin, SWERC 2004 ,LA3645

/*Sample Input
4
lisbon
berlin
1500
9
lisbon london 6 1000 1100
london lisbon 6 1130 1230
lisbon paris 5 1000 1100
paris lisbon 4 1130 1230
london paris 1 1130 1300
london berlin 2 1340 1510
berlin london 2 1300 1430
paris berlin 10 1330 1500
berlin paris 9 1300 1430
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

const int maxn = 1e4 + 5;

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

struct node
{
    string from, to;
    int cap, start, end;
} flight[maxn];

inline int dis(int a, int b)
{
    int t1 = (a / 100) * 60 + a % 100;
    int t2 = (b / 100) * 60 + b % 100;
    return t1 - t2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, m;
    while (cin >> n)
    {
        string S, T;
        int limit;
        cin >> S >> T >> limit;
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> flight[i].from >> flight[i].to >> flight[i].cap >> flight[i].start >> flight[i].end;
        int s = m << 1, t = s + 1;
        ans.init(t + 1);
        for (int i = 0; i < m; i++)
        {
            if (flight[i].from == S) ans.AddEdge(s, i, INF);
            if (flight[i].to == T && flight[i].end <= limit) ans.AddEdge(m + i, t, INF);
            ans.AddEdge(i, m + i, flight[i].cap);
            for (int j = 0; j < m; j++)
            {
                if (i == j) continue;
                if (flight[i].to == flight[j].from && dis(flight[j].start, flight[i].end) >= 30)
                    ans.AddEdge(m + i, j, INF);
            }
        }
        cout << ans.Maxflow(s, t) << endl;
    }
    return 0;
}
