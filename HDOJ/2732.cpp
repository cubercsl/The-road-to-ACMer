// Leapin' Lizards, HDU2732

/*Sample Input
4
3 1
1111
1111
1111
LLLL
LLLL
LLLL
3 2
00000
01110
00000
.....
.LLL.
.....
3 1
00000
01110
00000
.....
.LLL.
.....
5 2
00000000
02000000
00321100
02000000
00000000
........
........
..LLLL..
........
........
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

const int maxn = 1000;
const int maxm = 25;

char maze[maxm][maxm], P[maxm][maxm];

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

inline int dist (int a, int b, int c, int d)
{
    return abs(c - a) + abs(d - b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int T, n, m, d, cnt, kase = 0;
    cin >> T;
    while (T--)
    {
        cin >> n >> d;
        cnt = 0;
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        for (int i = 0; i < n; i++)
            cin >> P[i];
        m = strlen(maze[0]);
        int s = (n * m) << 1, t = s | 1;
        ans.init(t + 1);
        for (int i = 0; i < n; i++)
            for (int j = 0 ; j < m; j++)
                if (P[i][j] == 'L')
                {
                    cnt++;
                    ans.AddEdge(s, (i * m + j) << 1, 1);
                }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int cap = maze[i][j] - '0';
                if (!cap)
                    continue;
                if (i - d < 0 || i + d >= n || j - d < 0 || j + d >= m)
                {
                    ans.AddEdge((i * m + j) << 1, t, cap);
                    continue;
                }
                ans.AddEdge((i * m + j) << 1, (i * m + j) << 1 | 1, cap);
                for (int tx = -d; tx <= d; tx++)
                    for (int ty = -d; ty <= d; ty++)
                    {
                        int x = i + tx, y = j + ty;
                        if (dist(x, y, i, j) > d) continue;
                        ans.AddEdge((i * m + j) << 1 | 1, (x * m + y) << 1, INF);
                    }
            }
        int res = cnt - ans.Maxflow(s, t);
        cout << "Case #" << ++kase << ": ";
        if (res > 1)
            cout << res << " lizards were left behind." << endl;
        else if (res == 1)
            cout << "1 lizard was left behind." << endl;
        else
            cout << "no lizard was left behind." << endl;
    }
    return 0;
}
