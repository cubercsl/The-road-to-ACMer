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

const int maxn = 105;
char str[maxn];
int dp[maxn][maxn];

int dfs(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i >= j) return dp[i][j] = 0;
    if (str[i] == str[j]) return dp[i][j] = dfs(i + 1, j - 1);
    return dp[i][j] = min(dfs(i + 1, j), dfs(i, j - 1)) + 1;
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
        scanf("%s", str);
        printf("Case %d: %d\n", ++kase, dfs(0, strlen(str) - 1));
    }
    return 0;
}
