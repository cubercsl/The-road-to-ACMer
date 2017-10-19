// B-number, HDU3652

/*Sample Input
13
100
200
1000
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
int dp[15][15][3];
int dfs(int pos, int sum = 0, int state = 0, bool limit = true)
{
    if (pos == -1) return sum == 0 && state == 2;
    if (!limit && dp[pos][sum][state] != -1) return dp[pos][sum][state];
    int up = limit ? a[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; i++)
    {
        int next_state = state;
        if (state == 1 && i != 1) next_state = 0;
        if (state == 0 && i == 1) next_state = 1;
        if (state == 1 && i == 3) next_state = 2;
        ans += dfs(pos - 1, (sum * 10 + i) % 13, next_state, limit && i == a[pos]);
    }
    if (!limit) dp[pos][sum][state] = ans;
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
    int n;
    while (cin >> n)
        cout << solve(n) << endl;
    return 0;
}
