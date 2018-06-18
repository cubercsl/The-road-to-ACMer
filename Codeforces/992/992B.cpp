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
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    set<ll> div;
    for (ll d = 1; d * d <= y; d++)
        if (y % d == 0)
            div.insert(d), div.insert(y / d);
    set<pair<ll, ll>> ans;
    auto ok = [&](ll t) { return l <= t && t <= r; };
    for (auto& d : div)
    {
        ll tx = x * d, ty = y / d;
        if (ok(tx) && ok(ty) && __gcd(tx, ty) == x) ans.insert({tx, ty});
    }
    for (auto& t : ans) cout << t.X << " " << t.Y << endl;
    cout << ans.size() << endl;
}