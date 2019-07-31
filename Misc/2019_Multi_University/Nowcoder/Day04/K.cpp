#include <bits/stdc++.h>
using namespace std;

long long dp[1 << 17][300];

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    dp[0][s[0] - '0'] = 1;
    cerr << dp[0][6] << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            int k = (j * 10 + s[i] - '0') % 300;
            dp[i][k] += dp[i - 1][j];
        }
        dp[i][s[i] - '0']++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i][0];
    cout << ans << endl;
}