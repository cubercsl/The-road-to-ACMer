// Game of Sum, UVa10891

/*Sample Input
4
4 -10 -20 7
4
1 2 3 4
0
*/

#include <bits/stdc++.h>
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
int n;
int dp[maxn][maxn];
int vis[maxn][maxn];
int pre[maxn];

void init()
{
    clr(dp, 0);
    clr(vis, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][i];
        vis[i][i] = 1;
        pre[i] = pre[i - 1] + dp[i][i];
    }
}

int dfs(int x, int y)
{
    if (vis[x][y]) return dp[x][y];
    vis[x][y] = 1;
    int tmp = 0;
    for (int i = 1; i <= y - x + 1; i++)
    {
        tmp = min(dfs(x, y - i), tmp);
        tmp = min(dfs(x + i, y), tmp);
    }
    return dp[x][y] = pre[y] - pre[x - 1] - tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n, n)
    {
        init();
        int ans = dfs(1, n);
        cout << 2 * ans - pre[n] << endl;
    }
    return 0;
}
