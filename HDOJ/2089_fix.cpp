// 不要62, HDU2089

/*Sample Input
1 100
0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int a[10];
int dp[10][2];
int dfs(int pos, int state = 0, int pre = -1, bool limit = true)
{
    if (pos == -1) return 1;
    if (!limit && dp[pos][state] != -1) return dp[pos][state];
    int up = limit ? a[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i == 4 || pre == 6 && i == 2) continue;
        ans += dfs(pos - 1, i == 6, i, limit && i == a[pos]);
    }
    if (!limit) dp[pos][state] = ans;
    return ans;
}

int solve(int x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(dp, -1);
    int n, m;
    while (cin >> n >> m, n + m)
        cout << solve(m) - solve(n - 1) << endl;
    return 0;
}
