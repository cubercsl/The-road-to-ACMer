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

int findl(const vector<int>& v, int x)
{
    int l = 0, r = v.size() - 1;
    int ans = INF;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (v[m] >= x)
            ans = m, r = m - 1;
        else
            l = m + 1;
    }
    return ans;
}

int findr(const vector<int>& v, int x)
{
    int l = 0, r = v.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (v[m] <= x)
            ans = m, l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, m, a, b, v;
    cin >> n >> m >> a >> b >> v;
    vector<int> s(a), e(b);
    for (auto& t : s) cin >> t;
    for (auto& t : e) cin >> t;
    int q;
    cin >> q;
    while (q--)
    {
        ll ans = 1e18;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) ans = abs(y1 - y2);
        int d = abs(x2 - x1);
        if (y1 > y2) swap(y1, y2);
        int l = findl(e, y1);
        int r = findr(e, y2);
        if (l <= r) ans = min(ans, 1LL * (y2 - y1) + (d + v - 1) / v);
        l = findl(s, y1), r = findr(s, y2);
        if (l <= r) ans = min(ans, 1LL * (y2 - y1) + d);
        l = findr(e, y1), r = findl(e, y2);
        if (~l) ans = min(ans, 1LL * (y2 - y1) + 2 * (y1 - e[l]) + (d + v - 1) / v);
        if (r != INF) ans = min(ans, 1LL * (y2 - y1) + 2 * (e[r] - y2) + (d + v - 1) / v);
        l = findr(s, y1), r = findl(s, y2);
        if (~l) ans = min(ans, 1LL * (y2 - y1) + 2 * (y1 - s[l]) + d);
        if (r != INF) ans = min(ans, 1LL * (y2 - y1) + 2 * (s[r] - y2) + d);
        cout << ans << endl;
    }
    return 0;
}
