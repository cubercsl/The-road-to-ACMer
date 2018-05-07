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

const int N = 1 << 18;
int fa[N];
int in[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same(int x, int y) { return find(x) == find(y); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}
vector<int> G[N];

bool ok(const vector<int>& v)
{
    for (auto& t : v)
        if (in[t] != 2) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    iota(fa, fa + n + 1, 0);
    int ans = 0;
    while (m--)
    {
        static int u, v;
        cin >> u >> v;
        if (!same(u, v))
            unite(u, v);
        in[u]++, in[v]++;
    }
    for (int i = 1; i <= n; i++)
        G[find(i)].push_back(i);
    for (int i = 1; i <= n; i++)
        if (find(i) == i && ok(G[i])) ans++;
    cout << ans << endl;
    return 0;
}