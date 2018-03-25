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

ll dp[70][70][70];
int a[70];

ll dfs(int pos, int state, int count, bool limit = true)
{
    if (pos == -1) return state == count;
    if (~dp[pos][state][count] && !limit) return dp[pos][state][count];
    int up = limit ? a[pos] : 1;
    ll ans = 0;
    for (int i = 0; i <= up; i++) ans += dfs(pos - 1, state + i, count, limit & i == a[pos]);
    if (!limit) dp[pos][state][count] = ans;
    return ans;
}

ll solve(ll n, int cnt)
{
    int pos = 0;
    do
        a[pos++] = n & 1;
    while (n >>= 1);
    return dfs(pos - 1, 0, cnt);
}

inline int gao(ll n)
{
    int ret = 0;
    do
        ret += n & 1;
    while (n >>= 1);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    clr(dp, -1);
    scanf("%d", &T);
    while (T--)
    {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        int pop_count = gao(n);
        // printf("pop = %d\n", pop_count);
        ll cnt = solve(n, pop_count);
        ll tar = cnt + k;
        // printf("cnt = %lld\n", cnt);
        ll l = n + 1, r = 1;
        while (r < l) r <<= 1;
        --r;
        ll tmp = solve(r, pop_count);
        printf("Case #%d: ", ++kase);
        if (tmp < tar)
        {   
            puts("IMPOSSIBLE");
            continue;
        }
        // printf("l = %lld r = %lld\n", l, r);
        while (l <= r)
        {
            ll m = l + r >> 1;
            // printf("m = %lld\n", m);
            ll cnt = solve(m, pop_count);
            // printf("cnt = %lld\n", cnt);

            if (cnt < tar)
                l = m + 1;
            else
                r = m - 1;
        }
        printf("%lld\n", l);
    }
    return 0;
}