#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int T;
    scanf("%d", &T);
    vector<int> cnt(1 << 10);
    for (int i = 1; i < (1 << 10); i++) cnt[i] = cnt[i >> 1] + (i & 1);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> dp(1 << n);
        dp[0] = 1;
        while (m--)
        {
            static char op[5];
            static int u, v;
            scanf("%s%d%d", op, &u, &v);
            --u, --v;
            int s = (1 << u) | (1 << v);
            if (op[0] == '-')
            {
                for (int i = (1 << n) - 1; ~i; i--)
                    if ((s & i) == s)
                        dp[i] = (dp[i] - dp[i ^ s] + mod) % mod;
            }
            else
            {
                for (int i = 0; i < (1 << n); i++)
                    if ((s & i) == s)
                        dp[i] = (dp[i] + dp[i ^ s]) % mod;
            }
            vector<int> ans(n / 2 + 1);
            for (int i = 0; i < (1 << n); i++)
            {
                int p = cnt[i] >> 1;
                ans[p] = (ans[p] + dp[i]) % mod;
            }
            for (int i = 1; i <= n / 2; i++) printf("%d%c", ans[i], " \n"[i == n / 2]);
        }
    }
    return 0;
}