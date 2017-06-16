#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[105][4];
int a[105];
int ans;

int main()
{
    int n;
    while (cin >> n)
    {
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            if (a[i] == 1 || a[i] == 3)
                dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1] + 1, dp[i - 1][2]));
            if (a[i] == 2 || a[i] == 3)
                dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2] + 1));
        }
        ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
        cout << ans << endl;
    }
    return 0;
}
