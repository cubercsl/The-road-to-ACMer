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

typedef pair<ll, PII> Edge;
vector<Edge> G;
vector<Edge> tG;
const int N = 10005;
int fa[N];

inline void init(int n)
{
    for (int i = 0; i <= n; i++) fa[i] = i;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    fa[y] = x;
}

bool same(int x, int y) { return find(x) == find(y); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m, s, t;
    cin >> n >> m;
    init(n);
    while (m--)
    {
        static int u, v;
        ll c;
        cin >> u >> v >> c;
        G.pb(mp(c, mp(u, v)));
        unite(u, v);
    }
    cin >> s >> t;
    if (!same(s, t))
    {
        cout << -1 << endl;
        return 0;
    }
    cerr << "test" << endl;
    ll ans = (1LL << 62) - 1;
    for (int i = 61; ~i; i--)
    {
        init(n);
        for (auto& e : G)
        {
            ll w = e.X;
            int u = e.Y.X, v = e.Y.Y;
            if (!(w >> i & 1)) unite(u, v), tG.pb(mp(w, mp(u, v)));
        }
        if (same(s, t))
        {
            ans ^= (1LL << i);
            swap(G, tG);
        }
        tG.clear();
    }
    cout << ans << endl;
    return 0;
}
