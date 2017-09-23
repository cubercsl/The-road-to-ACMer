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

const int N = 1e5 + 5;
vector<int> G[N];
set<int> s[2];

void init()
{
    for (int i = 0; i < N; i++)
        G[i].clear();
    s[0].clear();
    s[1].clear();
}

void add_edge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

void dfs(int u, int p, bool flag)
{
    s[flag].insert(u);
    for (auto& v : G[u])
    {
        if (v == p) continue;
        dfs(v, u, flag ^ 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    fastin int n;
    while (cin >> n)
    {
        fastin
        init();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        }
        dfs(1, 1, 0);
        ll ans = 1LL * s[0].size() * s[1].size();
        ans -= (n - 1);
        cout << ans << endl;
    }
    return 0;
}
