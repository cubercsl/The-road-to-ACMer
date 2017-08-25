// Apple Tree, POJ2486

/*Sample Input
2 1 
0 11
1 2
3 2
0 1 2
1 2
1 3
*/

#include <iostream>
#include <cstring>
#include <vector>
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

const int maxn = 105;
const int maxk = 205;
int n, k;
vector <int> G[maxn];
int dp[maxn][maxk][2]; //back or not
int val[maxn];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        G[i].clear();
    clr(dp, 0);
}

void dfs(int u, int f)
{
    for (int i = 0; i <= k; i++)
        dp[u][i][0] = dp[u][i][1] = val[u];
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == f) continue;
        dfs(v, u);
        for (int j = k; j >= 0; j--)
            for (int p = 1; p <= j; p++)
            {
                if (p >= 2)
                {
                    dp[u][j][0] = max(dp[u][j][0], dp[u][j - p][0] + dp[v][p - 2][0]);  //返回根结点
                    dp[u][j][1] = max(dp[u][j][1], dp[u][j - p][1] + dp[v][p - 2][0]);  //返回后去其他子树
                }
                dp[u][j][1] = max(dp[u][j][1], dp[u][j - p][0] + dp[v][p - 1][1]);      //不返回根结点
            }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n >> k)
    {
        init(n);
        int a, b;
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1, 0);
        cout << max(dp[1][k][0], dp[1][k][1]) << endl;
    }
    return 0;
}
