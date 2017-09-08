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
const double eps = 1e-6;

const int maxn = 1005;
int dp[maxn][maxn];
int a[maxn][maxn];

int n, m;
int dfs(int x, int y)
{
    if (x >= n || y >= m) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int a1 = dfs(x + 1, y);
    int a2 = dfs(x, y + 1);
    int a3 = dfs(x + 1, y + 1);
    return dp[x][y] = max(a1, max(a2, a3)) + a[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        clr(dp, -1);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        printf("Scenario #%d:\n%d\n\n", ++kase, dfs(0, 0));
    }
    return 0;
}
