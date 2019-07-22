#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
const int mod = 1e9 + 7;
vector<int> vec[505];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
int dp[2][100][300];
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) vec[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int x = i;
            int y = 0;
            int flag = 0;
            for (int j = 0; j < 8; j++)
            {
                int cnt = 0;
                while (x % prime[j] == 0)
                {
                    cnt++;
                    y |= (1 << j);
                    x /= prime[j];
                }
                if (cnt > 1) flag = 1;
            }
            if (!flag)
                vec[x].push_back(y);
        }
        k = min(k, 99);
        memset(dp, 0, sizeof(dp));
        dp[1][0][0] = 1;
        for (int i = 0; i < vec[1].size(); i++)
        {
            for (int j = k; j > 0; j--)
            {
                for (int s = 255; ~s; s--)
                {
                    if ((s & vec[1][i]) == vec[1][i])
                        (dp[1][j][s] += dp[1][j - 1][s ^ vec[1][i]]) %= mod;
                }
            }
        }
        // for(int i=0;i<=k;i++){
        //     for(int s = 0; s <= 4; s++){
        //         cout << dp[1][i][s] << ' ';
        //     }
        //     cout << endl;
        // }
        for (int i = 2; i <= n; i++)
        {
            int id = i & 1;
            // memcpy(dp[id], dp[id^1],sizeof(dp[id]));
            for (int stat = 0; stat < (1 << 8); stat++)
            {
                dp[id][0][stat] = dp[id ^ 1][0][stat];
                for (int j = 1; j <= k; j++)
                {
                    dp[id][j][stat] = dp[id ^ 1][j][stat];
                    for (auto& x : vec[i])
                    {
                        if ((stat & x) == x)
                        {
                            // cout << "i = " << i << endl;
                            (dp[id][j][stat] += dp[id ^ 1][j - 1][stat ^ x]) %= mod;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < (1 << 8); j++)
                ans = (ans + dp[n & 1][i][j]) % mod;
        printf("%lld\n", ans);
    }
}