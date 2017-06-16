// Max Sum Plus Plus, HDU1024

/*Sample Input
1 3 1 2 3
2 6 -1 4 -2 3 -2 3
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int s[1000010];
int m, n;
int ans;
int dp[1000010];
int premax[1000010];

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        ans = -INF;
        for (int j = i; j <= n; j++)
        {
            dp[j] = max(dp[j - 1] + s[j], premax[j - 1] + s[j]);
            premax[j - 1] = ans;
            ans = max(ans, dp[j]);
        }
    }
}

int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        memset(premax, 0, sizeof(premax));
        for (int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        solve();
        printf("%d\n", ans);
    }
    return 0;
}
