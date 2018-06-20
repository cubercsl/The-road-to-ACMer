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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<VI> G(n);
    vector<int> fa(n), deg(n);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
    auto unite = [&](int x, int y) {
        x = find(x), y = find(y);
        if (x != y) fa[x] = y;
    };
    vector<PII> ans;
    while (m--)
    {
        static int u, v;
        cin >> u >> v;
        --u, --v;
        unite(u, v);
        G[u].push_back(v);
        deg[v]++;
    }
    vector<VI> GG(n);
    vector<int> dag;
    auto check = [&](const vector<int>& g) {
        queue<int> q;
        dag.clear();
        int m = g.size();
        for (auto& u : g)
            if (!deg[u]) q.push(u);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            --m;
            dag.push_back(u);
            for (auto& v : G[u])
                if (--deg[v] == 0) q.push(v);
        }
        return m;
    };
    for (int i = 0; i < n; i++) GG[find(i)].push_back(i);
    for (auto& g : GG)
    {
        if (g.empty()) continue;
        if (check(g))
        {
            int m = g.size();
            for (int i = 0; i < m; i++) ans.push_back({g[i], g[(i + 1) % m]});
        }
        else
        {
            int m = dag.size();
            for (int i = 0; i + 1 < m; i++) ans.push_back({dag[i], dag[i + 1]});
        }
    }
    cout << ans.size() << endl;
    for (auto& t : ans) cout << t.X + 1 << " " << t.Y + 1 << endl;
    return 0;
}