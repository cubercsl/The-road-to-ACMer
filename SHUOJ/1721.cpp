#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000][1000];
ll dfs(int n, int m)
{
    if (~dp[n][m]) return dp[n][m];
    ll& ret = dp[n][m];
    if (m == 1) return ret = n;
    if (n <= 1 || m == 0) return ret = 1;
    return ret = dfs(n - 1, m) + dfs(n, m - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    while (cin >> n >> m)
        cout << dfs(n, m) << endl;
    return 0;
}