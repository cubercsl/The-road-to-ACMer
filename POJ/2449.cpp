// Remmarguts' Date, POJ2449

/*Sample Input
2 2
1 2 5
2 1 4
1 2 2
*/

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

const int maxn = 1 << 10;
vector<PII> G[maxn], rG[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
        rG[i].clear();
    }
}
inline void add_edge(int u, int v, int w)
{
    G[u].pb(mp(w, v));
    rG[v].pb(mp(w, u));
}
int d[maxn];
bool vis[maxn];
void Dijkstra(int s)
{
    clr(vis, 0), clr(d, 0x3f);
    d[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push(mp(d[s], s));
    while (!q.empty())
    {
        PII t = q.top();
        int x = t.Y;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < rG[x].size(); i++)
        {
            int y = rG[x][i].Y, w = rG[x][i].X;
            if (!vis[y] && d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                q.push(mp(d[y], y));
            }
        }
    }
}

struct HeapNode
{
    int v, g, f;
    HeapNode(int v, int g, int f) : v(v), g(g), f(f) {}
    bool operator<(const HeapNode& rhs) const
    {
        return rhs.f < f || (rhs.f == f && rhs.g < g);
    }
};
int A_star(int s, int t, int k)
{
    if (s == t) k++;
    if (d[s] == INF) return -1;
    priority_queue<HeapNode> q;
    int cnt = 0;
    q.push(HeapNode(s, 0, d[s]));
    while (!q.empty())
    {
        HeapNode tmp = q.top();
        q.pop();
        int u = tmp.v, g = tmp.g;
        if (u == t) cnt++;
        if (cnt == k) return tmp.g;
        for (int i = 0; i < G[u].size(); i++)
        {
            PII& e = G[u][i];
            int v = e.Y, w = e.X;
            q.push(HeapNode(v, g + w, g + w + d[v]));
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        init(n);
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--, v--;
            add_edge(u, v, w);
        }
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);
        s--, t--;
        Dijkstra(t);
        printf("%d\n", A_star(s, t, k));
    }
    return 0;
}
