#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int dp[N][N];
vector<int> col;
int dfs(int l, int r)
{
    if (~dp[l][r]) return dp[l][r];
    int& ret = dp[l][r];
    if (l == r)
        ret = 0;
    else if (l + 1 == r)
        ret = 1;
    else if (col[l] == col[r])
        ret = dfs(l + 1, r - 1) + 1;
    else
        ret = min(dfs(l + 1, r), dfs(l, r - 1)) + 1;
    return ret;
}

int main()
{
    int n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    col.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (col.back() != a[i])
            col.push_back(a[i]);
    }
    cout << dfs(0, col.size() - 1) << endl;
}