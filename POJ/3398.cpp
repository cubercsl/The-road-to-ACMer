// Perfect Service, POJ3398

/*Sample Input
6
1 3
2 3
3 4
4 5
4 6
0
2
1 2
-1
*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 10005;
vector <int> G[maxn];
int dp[maxn][3];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        G[i].clear();
    clr(dp, 0x3f);
}

void addedge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

void dfs(int u, int p)
{
    dp[u][0] = 1, dp[u][2] = 0;
    int sum = 0, inc = INF;
    bool flag = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += min(dp[v][0], dp[v][2]);
        if (dp[v][0] <= dp[v][1])
            sum += dp[v][0], flag = 1;
        else
            sum += dp[v][1], inc = min(inc, dp[v][0] - dp[v][1]);
        dp[u][2] += dp[v][1];
        dp[u][2] = min(dp[u][2], INF);
    }
    if (!flag && inc != INF) dp[u][1] = INF;
    else
    {
        dp[u][1] = sum;
        if (!flag) dp[u][1] += inc;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        int u, v, tmp;
        init(n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        dfs(1, 1);
        int ans = min(dp[1][0], dp[1][1]);
        printf("%d\n", ans);
        scanf("%d", &tmp);
        if (tmp) break;
    }

    return 0;
}
