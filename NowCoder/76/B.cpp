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

const int N = 105;
int fa[N];
typedef pair<int, PII> Edge;
vector<Edge> G;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    fa[y] = x;
}
bool same(int x, int y) { return find(x) == find(y); }

void add_edge(int u, int v, int d) { G.pb(mp(d, mp(u, v))); }
int Kruskal(int n)
{
    sort(G.begin(), G.end());
    int m = G.size();
    int num = 0, ret = 0;
    for (int i = 0; i < m; i++)
    {
        Edge p = G[i];
        int x = p.Y.X, y = p.Y.Y;
        int d = p.X;
        if (!same(x, y))
        {
            unite(x, y);
            num++;
            ret += d;
        }
        if (num == n - 1) break;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int c, n, m;
    while (~scanf("%d%d%d", &c, &m, &n))
    {
        for (int i = 0; i < n; i++) fa[i] = i;
        G.clear();
        while (m--)
        {
            static int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            --u, --v;
            add_edge(u, v, d);
        }
        puts(Kruskal(n) <= c ? "Yes" : "No");
    }
    return 0;
}