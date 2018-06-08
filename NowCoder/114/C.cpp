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
const int mod = 119 << 23 | 1;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<VI> G(n, VI(n));
    vector<VI> dp(1 << n, VI(n));
    vector<int> ans(k);
    while (m--)
    {
        static int u, v;
        cin >> u >> v;
        --u, --v;
        G[u][v] = G[v][u] = 1;
        dp[(1 << u) | (1 << v)][u] = dp[(1 << u) | (1 << v)][v] = 1;
    }
    for (int s = 1; s < (1 << n); s++)
    {
        int t = __builtin_ctz(s);
        for (int i = t + 1; i < n; i++)
            if (s >> i & 1)
            {
                for (int j = t + 1; j < n; j++)
                    if (s >> j & 1)
                        if (G[j][i]) (dp[s][i] += dp[s ^ (1 << i)][j]) %= mod;
                int cnt = __builtin_popcount(s);
                if (G[t][i] && cnt > 2) (ans[cnt % k] += dp[s][i]) %= mod;
            }
    }
    for (auto& t : ans) cout << (1LL * t * 499122177) % mod << endl;
    return 0;
}