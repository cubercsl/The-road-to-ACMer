#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 17;
const int mod = 1e9 + 7;

int main()
{
    vector<vector<ll>> dp(N, vector<ll>(2));
    dp[0][0] = 1;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < N; i++)
    {
        if (i >= k) dp[i][1] = dp[i - k][0];
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    for (int i = 1; i < N; i++) (dp[i][0] += (dp[i - 1][0] + dp[i][1])) %= mod;
    while(n--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = (dp[r][0] - dp[l - 1][0] + mod) % mod;
        printf("%lld\n", ans);
    }
}
