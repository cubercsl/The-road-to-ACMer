#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll dp[70][10][1000];
ll a[70], s[70];

int dic[] = {1, -1, -1, 1};

ll dfs(int pos, int last = -1, int sum = 0, bool limit = true)
{
    if (pos == -1) return abs(sum);
    if (!limit && ~dp[pos][last + 1][sum + 500]) return dp[pos][last + 1][sum + 500];
    ll ans = 0;
    int up = limit ? a[pos] : 1;
    for (int i = 0; i <= up; i++)
        (ans += dfs(pos - 1,
                    (i == 0 && last == -1) ? -1 : i,
                    sum + (last == -1 ? 0 : dic[last * 2 + i]),
                    limit && i == a[pos]))
            %= mod;
    if (!limit) dp[pos][last + 1][sum + 500] = ans;
    return ans;
}

ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x & 1;
    while (x >>= 1);
    return dfs(pos - 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}