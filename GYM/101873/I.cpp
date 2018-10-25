#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int dp[maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = -1000000;
    for (int i = m + 1; i <= 2 * m + 1; i++)
        dp[i] = a[i], ans = max(ans, dp[i]);
    if (m + 1 > n)
    {
        printf("0\n");
        return 0;
    }
    int id = m + 1;
    int Max = dp[id++];
    for (int i = 2 * m + 1; i <= n; i++)
    {
        dp[i] = a[i] + Max;
        ans = max(ans, dp[i]);
        Max = max(Max, dp[id++]);
    }
    printf("%d\n", ans);
}