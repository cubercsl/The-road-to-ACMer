#include <bits/stdc++.h>
using namespace std;

bool vis[105][100005];
int dp[105][100005];
pair<int, long long> s[100005];
int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        int n, m, k;
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 0, x, y; i < k; i++)
        {
            scanf("%d%d", &y, &x);
            vis[x][y] = 1;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = m; j; j--)
                if (vis[i][j] == 0)
                    dp[i][j] = dp[i][j + 1] + 1;
        for (int j = 1; j <= m; j++)
        {
            long long sum = 0;
            int top = 0;
            for (int i = n; i; i--)
            {
                if (vis[i][j])
                {
                    top = 0, sum = 0;
                    continue;
                }
                long long cnt = 0;
                while (top && s[top].first >= dp[i][j]) cnt += s[top].second, sum -= s[top].second * s[top].first, --top;
                s[++top] = {dp[i][j], cnt + 1};
                sum += dp[i][j] * (cnt + 1);
                ans += sum;
            }
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
}