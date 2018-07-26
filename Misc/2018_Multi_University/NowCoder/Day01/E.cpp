#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n, m, l;
    while (~scanf("%d%d%d", &n, &m, &l))
    {
        vector<int> s(n);
        for (int i = 0; i < n; i++) scanf("%d", &s[i]);
        vector<vector<int>> dp(m + 1, vector<int>(l + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> new_dp(m + 1, vector<int>(l + 1));
            for (int j = 0; j <= m; j++)

                for (int k = 0; k <= l; k++)
                {
                    if (j < m && k != s[i]) (new_dp[j + 1][k] += dp[j][k]) %= mod;
                    (new_dp[j][s[i]] += dp[j][k]) %= mod;
                }
            dp.swap(new_dp);
        }
        int ans = 0;
        for (int i = 0; i <= l; i++) (ans += dp[m][i]) %= mod;
        printf("%d\n", ans);
    }
    return 0;
}