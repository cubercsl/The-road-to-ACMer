#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2000][2000];

ll dfs(int n, int m)
{
    if (~dp[n][m]) return dp[n][m];
    ll& ret = dp[n][m];
    if (n < m) return ret = 0;
    if (n == 1 || m == 0) return ret = 1;
    ret = 0;
    for (int i = 0; i <= m; i++)
        ret += dfs(n - 1, i);
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    while (cin >> n >> m)
        cout << dfs(n, m) << endl;
    return 0;
}