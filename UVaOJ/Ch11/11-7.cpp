// Lift Hopping, UVa10801

/*Sample Input
2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10
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

const int N = 5;
const int maxn = 1005;
struct Edge
{
    int from, to, dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};

struct HeapNode
{
    int d, u;
    HeapNode(int _d, int _u) : d(_d), u(_u) {}
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};

struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.pb(Edge(from, to, dist));
        m = edges.size();
        G[from].pb(m - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        clr(d, 0x3f);
        d[s] = 0;
        clr(done, 0);
        q.push(HeapNode(0, s));
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    q.push(HeapNode(d[e.to], e.to));
                }
            }
        }
    }
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, k;
    int t[N];
    string line;
    while (cin >> n >> k)
    {
        ans.init(700);
        for (int i = 0; i < n; i++)
            cin >> t[i];
        for (int i = 0; i < 100; i++)
            ans.AddEdge(i, 100 + i, 60);
        getline(cin, line);
        for (int i = 0; i < n; i++)
        {
            int x, y = -1;
            getline(cin, line);
            // cout << line << endl;
            stringstream ss(line);
            while (ss >> x)
            {
                ans.AddEdge(100 + x, 200 + 100 * i + x, 0);
                ans.AddEdge(200 + 100 * i + x, x, 0);
                if (y != -1)
                {
                    ans.AddEdge(200 + 100 * i + y, 200 + 100 * i + x, (x - y) * t[i]);
                    ans.AddEdge(200 + 100 * i + x, 200 + 100 * i + y, (x - y) * t[i]);
                }
                y = x;
            }
        }
        ans.dijkstra(100);
        int ret = ans.d[k];
        if (ret != INF)
            cout << ret << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
