// Island Transport, HDU4280

/*Sample Input
2
5 7
3 3
3 0
3 1
0 0
4 5
1 3 3
2 3 4
2 4 3
1 5 6
4 5 3
1 4 4
3 4 2
6 7
-1 -1
0 1
0 2
1 0
1 1
2 3
1 2 1
2 3 6
4 5 5
5 6 3
1 4 6
2 5 5
3 6 4
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

const int maxn = 1e5 + 5;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct ISAP
{
    int n, m, s, t;         //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<Edge> edges;     //边表。edges[e]和edges[e^1]互为反向弧
    vector<int> G[maxn];    //邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];         //BFS使用
    int d[maxn];            //起点到i的距离
    int cur[maxn];          //当前弧下标
    int p[maxn];            //可增广路上的一条弧
    int num[maxn];          //距离标号计数

    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void addedge(int from, int to, int cap)
    {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));
        int m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }

    int Augumemt()
    {
        int x = t, a = INF;
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
                Edge& e = edges[G[x][i] ^ 1];
                if (!vis[e.from] && e.cap > e.flow)
                {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    q.push(e.from);
                }
            }
        }
    }

    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
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
                if (e.cap > e.flow && d[x] == d[e.to] + 1)  //Advance
                {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;
                }
            }
            if (!ok)    //Retreat
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
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, x, y, z;
        int minv = INF, maxv = -INF;
        int s , t;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            if (x < minv)
                s = i, minv = x;
            if (x > maxv)
                t = i, maxv = x;
        }
        ans.init(n);
        while (m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            x--, y--;
            ans.addedge(x, y, z);
            ans.addedge(y, x, z);
        }
        printf("%d\n", ans.Maxflow(s, t));
    }
    return 0;
}
