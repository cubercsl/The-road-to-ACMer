// Bomb, HDU3555

/*Sample Input
3
1
50
500
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

int a[20];
ll dp[20][2];
ll dfs(int pos, int state = 0, int pre = -1, bool limit = true)
{
    if (pos == -1) return 1;
    if (!limit && dp[pos][state] != -1) return dp[pos][state];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (pre == 4 && i == 9) continue;
        ans += dfs(pos - 1, i == 4, i, limit && i == a[pos]);
    }
    if (!limit) dp[pos][state] = ans;
    return ans;
}

ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1) - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(dp, -1);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", n - solve(n));
    }
    return 0;
}
