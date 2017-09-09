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
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        memset(M, 0, sizeof(M[0][0]) * maxn * maxn);
        memset(G, 0, sizeof(G[0][0]) * maxn * maxn);
        memset(vis, 0, sizeof(vis[0][0]) * maxn * maxn);
        for (int i = 0; i < maxn; i++) ans[i].clear();

        int n, m;
        cin >> n >> m;
        int maxi = 0, maxj = 0, maxk = 0;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            M[u][v] = 1;
            maxi = max(maxi, u);
            maxj = max(maxj, v);
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u][v] = 1;
            maxk = max(maxk, v);
        }
        for (int i = 1; i <= maxi; i++)
            for (int k = 1; k <= maxj; k++)
                if (M[i][k] == 1)
                    for (int p = 1; p <= maxk; p++)
                        if (G[k][p] == 1)
                            if (vis[i][p] == 0)
                            {
                                vis[i][p] = 1;
                                ans[i].push_back(p);
                            }
        for (int i = 1; i <= maxi; i++)
        {
            sort(ans[i].begin(), ans[i].end());
            for (int k = 0; k < ans[i].size(); k++)
            {
                cout << i << ' ' << ans[i][k] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
