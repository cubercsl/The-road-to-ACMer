// Monkeys in the Emei Mountain, UVa11167

/*Sample Input
3  1
2  2  9
2  3  5
3  5  8
2  1
4  5  9
4  8  12
5  2
2  1  3
2  3  5
2  5  7
2  1  7
4  2  6
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

const int maxn = 1 << 16;
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
    int v, a, b;
    node() {}
    node(int _v, int _a, int _b) : v(_v), a(_a), b(_b) {}
} monkey[1005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, kase = 0;
    while (~scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        vector<int> Time;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int v, a, b;
            scanf("%d%d%d", &v, &a, &b);
            monkey[i] = node(v, a, b);
            sum += v;
            Time.pb(a), Time.pb(b);
        }
        sort(Time.begin(), Time.end());
        auto it = unique(Time.begin(), Time.end());
        Time.erase(it, Time.end());
        int s = n + Time.size(), t = s + 1;
        ans.init(t + 1);
        for (int i = 0; i < n; i++)
        {
            ans.AddEdge(s, i, monkey[i].v);
            int a = lower_bound(Time.begin(), Time.end(), monkey[i].a) - Time.begin();
            int b = lower_bound(Time.begin(), Time.end(), monkey[i].b) - Time.begin();
            for (int j = a; j < b; j++)
                ans.AddEdge(i, n + j, Time[j + 1] - Time[j]);
        }
        for (int i = 0; i + 1 < Time.size(); i++)
            ans.AddEdge(n + i, t, m * (Time[i + 1] - Time[i]));
        int flow = ans.Maxflow(s, t);
        printf("Case %d: ", ++kase);
        if (flow != sum)
        {
            puts("No");
            continue;
        }
        puts("Yes");

        vector<int> T;
        for (auto& t : Time) T.pb(t);
        for (int i = 0; i < n; i++)
        {
            vector<int> Ans;
            for (auto& id : ans.G[i])
            {
                Edge& e = ans.edges[id];
                if (e.flow <= 0) continue;
                int x = e.to - n;
                Ans.pb(T[x]);
                Ans.pb(min(Time[x + 1], T[x] + e.flow));
                T[x] += e.flow;
                if (T[x] >= Time[x + 1])
                {
                    T[x] = Time[x] + T[x] - Time[x + 1];
                    if (T[x] > Time[x])
                    {
                        Ans.pb(Time[x]);
                        Ans.pb(T[x]);
                    }
                }
            }
            sort(Ans.begin(), Ans.end());
            for (int j = 0; j + 1 < Ans.size(); j++)
                if (Ans[j] == Ans[j + 1])
                {
                    Ans.erase(Ans.begin() + j);
                    Ans.erase(Ans.begin() + j);
                    j--;
                }
            printf("%d", (int)Ans.size() / 2);
            for (int j = 0; j < Ans.size(); j += 2)
                printf(" (%d,%d)", Ans[j], Ans[j + 1]);
            puts("");
        }
    }
    return 0;
}
