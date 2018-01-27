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
const int maxn = 1e5 + 5;

vector<int> G[maxn];
vector<int> foo;
int deg[maxn];
bool vis[maxn];
int cnt;
void dfs(int u)
{
    if (deg[u] & 1) cnt++;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i <= n; i++) G[i].clear();
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
            deg[u]++;
            deg[v]++;
        }

        if (n == 2) {
            if (m == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }

        foo.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            cnt = 0;
            if (!vis[i]) {
                dfs(i);
                vis[i] = true;
                foo.push_back(cnt);
            }
        }
        sort(foo.begin(), foo.end(), [](int a, int b) { return a > b; });

        if (foo.size() == 1) {
            int num = foo[0];
            if (num)
                cout << num / 2 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }
        int ans = foo.size();
        for (int i = 0; i < foo.size(); i++) {
            if (foo[i] > 2) ans += (foo[i] - 2) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}