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

vector<int> a;
ll dp[20][20];
ll dfs(int pos, int state = 0, bool limit = true)
{
    if (pos == -1) return state;
    if (!limit && ~dp[pos][state]) return dp[pos][state];
    ll ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
        ans += dfs(pos - 1, state + (i == 6), limit & a[pos] == i);
    if (!limit) dp[pos][state] = ans;
    return ans;
}

ll solve(ll n)
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
    clr(dp, -1);
    ll l, r;
    while (~scanf("%lld%lld", &l, &r))
        printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}