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
int tot;
int tmp[1 << 9];
int Rank[2525];
ll dp[20][2520][50];
ll dfs(int pos, int mod = 0, int lcm = 1, bool limit = true)
{
    if (pos == -1) return mod % lcm == 0;
    int id = Rank[lcm];
    if (!limit && dp[pos][mod][id] != -1) return dp[pos][mod][id];
    int up = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i)
            ans += dfs(pos - 1, (mod * 10 + i) % 2520, lcm * i / __gcd(lcm, i), limit && i == a[pos]);
        else
            ans += dfs(pos - 1, mod * 10 % 2520, lcm, limit && i == a[pos]);
    }
    if (!limit) dp[pos][mod][id] = ans;
    return ans;
}

ll solve(ll x)
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
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    fastin int t;
    clr(dp, -1);
    for (int i = 0; i < (1 << 9); i++)
    {
        tmp[i] = 1;
        for (int j = 1; j < 10; j++)
            if (i >> (j - 1) & 1)
                tmp[i] = tmp[i] * j / __gcd(tmp[i], j);
    }
    sort(tmp, tmp + (1 << 9));
    tot = unique(tmp, tmp + (1 << 9)) - tmp;
    // cout << tot << endl;
    for (int i = 0; i < tot; i++)
        Rank[tmp[i]] = i;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}
