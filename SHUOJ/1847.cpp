#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int a[21][21];
    int dp[22][22];
    int n;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= 2 * i; j++)
                cin >> a[i][j];
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j <= 2 * i; j++)
                dp[i][j] = max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j + 2])) + a[i][j];
        cout << dp[0][0] << endl;
    }
    return 0;
}
