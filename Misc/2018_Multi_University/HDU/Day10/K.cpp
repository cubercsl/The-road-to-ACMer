#include <bits/stdc++.h>
using namespace std;

const long long maxv = 1e9;
const int maxn = 1 << 17;
const int INF = 0x3f3f3f3f;
char s[maxn], t[maxn], a[maxn], b[maxn];
long long dp[maxn][2], x[maxn], y[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d%s%s%s", &n, s + 1, a + 1, b + 1);
        for (int i = 1; i <= n; i++) t[i] = '1' + '0' - s[i];
        t[1]++;
        for (int i = 1; i <= n; i++)
            if (t[i] == '2') t[i] = '0', t[i + 1]++;
        t[n + 1] = '0';
        x[0] = y[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == '0')
                x[i] = 1;
            else
            {
                x[i] = (x[i - 1] == -1) ? x[i - 1] : (x[i - 1] << 1);
                x[i] = min(x[i], maxv);
            }
            if (b[i] == '0')
                y[i] = 1;
            else
            {
                y[i] = (y[i - 1] == -1) ? y[i - 1] : (y[i - 1] << 1);
                y[i] = min(y[i], maxv);
            }
        }
        for (int i = 0; i <= n + 1; i++) dp[i][0] = dp[i][1] = INT_MAX;
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '0')
            {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
                if (~x[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1] + x[i]);
            }
            else
            {
                if (~x[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0] + x[i]);
            }
            if (t[i] == '0')
            {
                dp[i][1] = min(dp[i][1], dp[i - 1][1]);
                if (~y[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + y[i]);
            }
            else
            {
                if (~y[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + y[i]);
            }
        }
        printf("%lld\n", min(dp[n][0], dp[n][1] + 1));
    }
}