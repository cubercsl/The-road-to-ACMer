// Going Home, POJ2195

/*Sample Input
2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
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
struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];      //是否在队列中
    int d[maxn];        //bellmanford
    int p[maxn];        //上一条弧
    int a[maxn];        //可改进量

    void init(int n)
    {
        this-> n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.pb(Edge(from, to, cap, 0, cost));
        edges.pb(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }

    bool BellmanFord(int s, int t, int& flow, int& cost)
    {
        for (int i = 0; i < n; i++) d[i] = INF;
        clr(inq, 0);
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false;   // 当没有可增广的路时退出
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }

    int MincostMaxflow(int s, int t, int& cost)
    {
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost));
        return flow;
    }
} mcmf;

char maze[105][105];
vector <PII> M;
vector <PII> H;

inline int dist(PII a, PII b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m), n + m)
    {
        M.clear();
        H.clear();
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0 ; j < m; j++)
                if (maze[i][j] == 'm')
                    M.pb(mp(i, j));
                else if (maze[i][j] == 'H')
                    H.pb(mp(i, j));
        int tm = M.size(), th = H.size();
        int s = tm + th, t = s + 1;
        mcmf.init(t + 1);
        for (int i = 0; i < tm; i++)
        {
            mcmf.AddEdge(s, i, 1, 0);
            for (int j = 0; j < th; j++)
                mcmf.AddEdge(i, tm + j, INF, dist(M[i], H[j]));
        }
        for (int j = 0; j < th; j++)
            mcmf.AddEdge(tm + j, t, 1, 0);
        int cost;
        mcmf.MincostMaxflow(s, t, cost);
        printf("%d\n", cost);
    }
    return 0;
}
