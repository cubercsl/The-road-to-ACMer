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
    G[u].pb(mp(v, w));
    rG[v].pb(mp(u, w));
}
int d[maxn];
bool inq[maxn];
void spfa(int s)
{
    clr(d, 0x3f);
    clr(inq, 0);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < rG[u].size(); i++)
        {
            PII& e = rG[u][i];
            int v = e.X, w = e.Y;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                inq[v] = 1;
                q.push(v);
            }
        }
    }
}
struct HeapNode
{
    int v;
    ll g, f;
    HeapNode(int v, ll g, ll f) : v(v), g(g), f(f) {}
    bool operator<(const HeapNode& rhs) const
    {
        return rhs.f < f || (rhs.f == f && rhs.g < g);
    }
};
bool A_star(int s, int t, int k, int tt)
{
    if (s == t) k++;
    if (d[s] == INF) return false;
    priority_queue<HeapNode> q;
    int cnt = 0;
    q.push(HeapNode(s, 0, d[s]));
    while (!q.empty())
    {
        HeapNode tmp = q.top();
        q.pop();
        int u = tmp.v;
        ll g = tmp.g;
        if (u == t) cnt++;
        if (cnt == k) return tmp.g <= tt;
        for (int i = 0; i < G[u].size(); i++)
        {
            PII& e = G[u][i];
            int v = e.X, w = e.Y;
            q.push(HeapNode(v, g + w, g + w + d[v]));
        }
    }
    return false;
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
        int s, t, k, tt;
        scanf("%d%d%d%d", &s, &t, &k, &tt);
        s--, t--;
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--, v--;
            add_edge(u, v, w);
        }
        spfa(t);
        if (A_star(s, t, k, tt))
            puts("yareyaredawa");
        else
            puts("Whitesnake!");
    }
    return 0;
}