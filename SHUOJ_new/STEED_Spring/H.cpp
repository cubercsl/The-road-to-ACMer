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

ll dp[64][2];
int a[64];

ll dfs(int pos, int state, bool limit = true)
{
    if (pos == -1) return 1;
    if (!limit && ~dp[pos][state]) return dp[pos][state];
    int up = limit ? a[pos] : 1;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (state & i) continue;
        ans += dfs(pos - 1, i, limit & a[pos] == i);
    }
    if (!limit) dp[pos][state] = ans;
    return ans;
}

ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x & 1;
    while (x >>= 1);
    return dfs(pos - 1, 0) - 1;
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
        ll l = 0, r = 1e18, ans;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (solve(mid) >= n)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}