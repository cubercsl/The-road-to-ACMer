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
typedef unsigned long long ull;
vector<int> a;
int dp[22][11];
int dfs(int pos, int sum = 0, bool limit = true)
{
    if (sum == 10) return 1;
    if (sum > 10) return 0;
    if (pos == -1) return 0;
    if (!limit && ~dp[pos][sum]) return dp[pos][sum];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
        ans += dfs(pos - 1, sum + i, limit && i == a[pos]);
    if (!limit) dp[pos][sum] = ans;
    return ans;
}

int solve(ull n)
{
    a.clear();
    do
        a.pb(n % 10);
    while (n /= 10);
    return dfs(a.size() - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    clr(dp, -1);
    while (~scanf("%d", &n))
    {
        ull l = 0, r = 0xffffffffffffffff, ans;
        while (l <= r)
        {
            ull mid = l + (r - l) / 2;
            int tmp = solve(mid);
            if (tmp < n)
                l = mid + 1;
            else
                ans = mid, r = mid - 1;
        }
        printf("%llu\n", ans);
    }
    return 0;
}
