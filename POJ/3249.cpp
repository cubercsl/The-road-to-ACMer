// Test for Job, POJ3249

/*Sample Input
6 5
1
2
2
3
3
4
1 2
1 3
2 4
3 4
5 6
*/

#include <cstdio>
#include <cstring>
#include <vector>
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

const int maxn = 1 << 17;
bool in[maxn];
int val[maxn];
vector<int> G[maxn];
ll dp[maxn];

ll dfs(int u)
{
    if (~dp[u]) return dp[u];
    ll tmp = -1e18;
    dp[u] = val[u];
    for (int i = 0; i < G[u].size(); i++)
        tmp = max(tmp, dfs(G[u][i]));
    if (tmp != -1e18) dp[u] += tmp;
    return dp[u];
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
        clr(in, 0);
        clr(dp, -1);
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
            scanf("%d", val + i);
        }
        while (m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
            in[v] = 1;
        }
        ll ans = -1e18;
        for (int i = 1; i <= n; i++)
            if (!in[i])
                ans = max(ans, dfs(i));
        printf("%lld\n", ans);
    }
    return 0;
}
