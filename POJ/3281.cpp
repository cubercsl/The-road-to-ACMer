// Dining, POJ3281

/*Sample Input
4 3 3
2 2 1 2 3 1
2 2 2 3 1 2
2 2 1 3 1 2
2 1 1 3 3
*/

#include <iostream>
#include <cstring>
#include <vector>
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

const int maxn = 500;


bool F[105][105], D[105][105];

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct EdmonsKarp           //时间复杂度O(v*E*E)
{
    int n, m;
    vector<Edge> edges;     //边数的两倍
    vector<int> G[maxn];    //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    int a[maxn];            //起点到i的可改进量
    int p[maxn];            //最短路树上p的入弧编号
    void init(int n)
    {
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));  //反向弧
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    int Maxflow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {
            clr(a, 0);
            queue<int> q;
            q.push(s);
            a[s] = INF;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};

int main()
{
    int n, f, d;
    cin >> n >> f >> d;
    EdmonsKarp ans;
    ans.init(n * 2 + f + d + 2);
    clr(F, 0);
    clr(D, 0);
    for (int i = 0; i < n; i++)
    {
        int tf, td, tmp;
        cin >> tf >> td;
        while (tf--)
        {
            cin >> tmp;
            F[i][--tmp] = 1;
        }
        while (td--)
        {
            cin >> tmp;
            D[i][--tmp] = 1;
        }
    }
    int s = n * 2 + f + d, t = s + 1;
    for (int i = 0; i < f; i++)
        ans.AddEdge(s, n * 2 + i, 1);
    for (int i = 0; i < d; i++)
        ans.AddEdge(n * 2 + f + i, t, 1);
    for (int i = 0; i < n; i++)
    {
        ans.AddEdge(i, n + i, 1);
        for (int j = 0; j < f; j++)
            if (F[i][j]) ans.AddEdge(n * 2 + j, i, 1);
        for (int j = 0; j < d; j++)
            if (D[i][j]) ans.AddEdge(n + i, n * 2 + f + j, 1);
    }
    cout << ans.Maxflow(s, t) << endl;

    return 0;
}
