#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
typedef long long ll;
int n, m, mod;
const int maxn = 2e4 + 5;
int pre[maxn], num[maxn];
int dp[maxn][55][105];

int dfs(int pos, int k, int sum)
{
    if (n - pos < m - k) return NINF;
    if (k == m) return (pre[n] - pre[pos] + sum) % mod;

    int nxt = pos + 1;
    if (dp[pos][k][sum] != -1) return dp[pos][k][sum];

    return dp[pos][k][sum] = max(dfs(pos + 1, k, (sum + num[nxt]) % mod),
                                 sum + dfs(pos + 1, k + 1, num[nxt]));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    while (cin >> n >> m >> mod) {
        clr(dp, 0xc0);
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            num[i] %= mod;
            pre[i] = (pre[i - 1] + num[i]) % mod;
        }
        // cout << dfs(1, 1, num[1]) << endl;

        for (int i = n; i; i--)
        {
            for (int j = m; j; j--)
                for (int k = 0; k < mod; k++)
                    if (n - i < m - j)
                        continue;
                    else if (j == m)
                        dp[i][j][k] = (pre[n] - pre[i] + k) % mod;
                    else
                        dp[i][j][k] = max(dp[i + 1][j][(k + num[i + 1]) % mod], k + dp[i + 1][j + 1][num[i + 1]]);
        }
        cout << dp[1][1][num[1]] << endl;
    }
}