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

int a[64];
ll dp[15][64][1 << 10];

ll dfs(int base, int pos, int state = 0, bool lead = true, bool limit = true)
{
    if (pos == -1) return state == 0;
    if (!limit && !lead && dp[base][pos][state] != -1) return dp[base][pos][state];
    int up = limit ? a[pos] : base - 1;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        int next_state = lead && i == 0 ? state : state ^ (1 << i);
        ans += dfs(base, pos - 1, next_state, lead && i == 0, limit && i == a[pos]);
    }
    if (!limit && !lead) dp[base][pos][state] = ans;
    return ans;
}

ll solve(int base, ll x)
{
    int pos = 0;
    do
        a[pos++] = x % base;
    while (x /= base);
    return dfs(base, pos - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin clr(dp, -1);
    int q, b;
    ll l, r;
    cin >> q;
    while (q--)
    {
        cin >> b >> l >> r;
        cout << solve(b, r) - solve(b, l - 1) << endl;
    }
    return 0;
}
