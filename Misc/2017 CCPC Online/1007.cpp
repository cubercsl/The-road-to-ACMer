#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int dight[40], tmp[40];
ll dp[40][40][40][40];

ll dfs(int start, int pos, int s, bool limit, int k)
{
    if (pos < 0)
        return s;
    if (!limit && dp[pos][s][start][k] != -1)
        return dp[pos][s][start][k];
    int end;
    ll ret = 0;
    if (limit)
        end = dight[pos];
    else
        end = k - 1;
    for (int d = 0; d <= end; d++)
    {
        tmp[pos] = d;
        if (start == pos && d == 0)
            ret += dfs(start - 1, pos - 1, s, limit && d == end, k);
        else if (s && pos < (start + 1) / 2)
            ret += dfs(start, pos - 1, tmp[start - pos] == d, limit && d == end, k);
        else
            ret += dfs(start, pos - 1, s, limit && d == end, k);
    }
    if (!limit)
        dp[pos][s][start][k] = ret;
    return ret;
}

ll solve(int n, int k)
{
    clr(dight, 0);
    int tot = 0;
    do
        dight[tot++] = n % k;
    while (n /= k);
    return dfs(tot - 1, tot - 1, 1, 1, k);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(dp, -1);
    int t, l, r, L, R, kase = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &L, &R, &l, &r);
        printf("Case #%d: ", ++kase);
        ll ans = 0;
        for (int i = l; i <= r; i++)
        {
            ll cnt = solve(R, i) - solve(L - 1, i);
            ans += cnt * (i - 1) + (R - L + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
