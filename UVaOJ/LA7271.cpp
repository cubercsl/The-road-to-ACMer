#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[64][65537][5];
int mod[] = {3, 5, 17, 257, 65537};
int a[64], p[64][5];

inline int getid(int k)
{
    for (int i = 0; i < 5; i++)
        if (mod[i] == k) return i;
    assert(false);
}

ll dfs(int pos, int val, int id, bool limit)
{
    if (!~pos) return val == 0;
    if (!limit && ~dp[pos][val][id]) return dp[pos][val][id];
    int up = limit ? a[pos] : 1;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
        ans += dfs(pos - 1, (val - i * p[pos][id] + mod[id]) % mod[id], id, limit && i == a[pos]);
    if (!limit) dp[pos][val][id] = ans;
    return ans;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        p[0][i] = 1;
        for (int j = 1; j < 64; j++)
            p[j][i] = p[j - 1][i] * 3 % mod[i];
    }
    memset(dp, -1, sizeof(dp));
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, ans = 0;
        int k, pos = 0;
        scanf("%lld%d", &n, &k);
        int id = getid(k);
        do
            a[pos++] = n & 1;
        while (n >>= 1);
        for (int i = 0; i < k; i++)
            ans ^= (dfs(pos - 1, i, id, true) - (i == 0));
        printf("%lld\n", ans);
    }
}