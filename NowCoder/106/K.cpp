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

bool ok(ll m, int k, const vector<int>& v)
{
    ll cur = 0;
    int cnt = 1;
    for (auto& t : v)
    {
        if (cur + t <= m)
            cur += t;
        else if (t > m)
            return false;
        else
            cur = t, cnt++;
    }
    return cnt <= k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> v(n - 1);
    for (auto& t : v) cin >> t;
    ll l = 0, r = 1e12, ans;
    while (l <= r)
    {
        ll m = l + r >> 1;
        if (ok(m, k, v))
            ans = m, r = m - 1;
        else
            l = m + 1;
    }
    cout << ans << endl;
    return 0;
}
