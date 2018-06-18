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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), dp(n), pre(n);
    for (auto& t : a) cin >> t;
    int l = 0, r = 0;
    while (r < n)
    {
        while (r < n && a[r] == 1) r++;
        while (l < r) dp[l++] = r;
        r++;
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
    auto sum = [&](int l, int r) {
        if (l == 0) return pre[r];
        return pre[r] - pre[l - 1];
    };
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p = i;
        ll cur = a[i];
        while (p < n)
        {
            int cnt = dp[p] - p - 1;
            if (cur % k == 0)
            {
                ll cur_sum = sum(i, p);
                ll need_sum = cur / k;
                if (cur_sum <= need_sum && cur_sum + cnt >= need_sum) ans++;
            }
            p = dp[p];
            if (p == n) break;
            if (3e18 / cur < a[p])
                break;
            cur *= a[p];
        }
    }
    cout << ans << endl;
    return 0;
}