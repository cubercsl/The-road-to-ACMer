#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long fastpow(long long b)
{
    long long r = 1, base = 2;
    while (b)
    {
        if (b & 1)
            r = r * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return r;
}

int main()
{
    long long dp[100010];
    int n, l;
    while (cin >> n >> l)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= l; i++)
            dp[i] = fastpow(i - 1);
        long long sum = fastpow(l) - 1;
        for (int i = 1; l + i <= n; i++)
        {
            dp[l + i] = sum;
            sum = (sum + MOD - dp[i] + dp[l + i]) % MOD;
        }
        cout << dp[n] << endl;
    }
    return 0;
}