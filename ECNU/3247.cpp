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

struct Edge
{
    int u, v;
    double t;
    bool f;
    bool operator<(const Edge& rhs) const { return t < rhs.t; }
};
vector<Edge> edges;

const int N = 1 << 17;
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline bool same(int x, int y) { return find(x) == find(y); }
inline void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    fa[y] = x;
}
bool check(double k, double M, const int& n)
{
    for (int i = 0; i <= n; i++) fa[i] = i;
    vector<Edge> G;
    for (auto e : edges)
    {
        if (e.f) e.t *= k;
        G.push_back(e);
    }
    sort(G.begin(), G.end());
    int cnt = 0;
    double ret = 0;
    for (auto& e : G)
    {
        double& w = e.t;
        int &u = e.u, &v = e.v;
        if (!same(u, v))
        {
            unite(u, v);
            cnt++;
            ret += w;
        }
        if (cnt == n - 1) break;
    }
    return ret < M || fabs(ret - M) < eps;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    double M;
    cin >> n >> m >> M;
    while (m--)
    {
        static int u, v;
        static double t;
        static bool f;
        cin >> u >> v >> t >> f;
        edges.push_back((Edge){u, v, t, f});
    }
    double l = 1, r = 1e15;
    while (fabs(r - l) > eps)
    {
        double k = (l + r) / 2;
        if (check(k, M, n))
            l = k;
        else
            r = k;
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}
