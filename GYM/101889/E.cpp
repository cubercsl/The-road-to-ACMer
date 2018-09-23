#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int dp[maxn][maxn];
string line;
string ans;
bool ok;
int mod;
int dfs(int pos, int val)
{
    if (ok) return 1;
    if (pos == line.size())
    {
        if (val == 0) {
            ok = true;
            cout << ans << endl;
            return 1;
        }
        else
            return -1;
    }
    if (dp[pos][val] != 0) return dp[pos][val];
    if (line[pos] != '?') {
        ans.push_back(line[pos]);
        int tmp = dfs(pos + 1, ((line[pos] - '0') + val * 10) % mod);
        // return dp[pos][val] = tmp;
        if(tmp == 1)
        return dp[pos][val] = 1;
        ans.pop_back();
        return dp[pos][val] = -1;
    }
    int s = (pos == 0) ? 1 : 0;
    for (int i = s; i <= 9;i++){
        ans.push_back('0' + i);
        int tmp = dfs(pos + 1, (val * 10 + i) % mod);
        if(tmp == 1)
            return dp[pos][val] = 1;
        ans.pop_back();
    }
    return dp[pos][val] = -1;
}
int main()
{
    cin >> line;
    cin >> mod;
    dfs(0, 0);
    if (!ok) cout << "*" << endl;
    // cin >> line;
}