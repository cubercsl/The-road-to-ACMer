#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll count(ll n)
{
    if (n == 1) return 1;
    return static_cast<ll>(ceil(0.5 * log10(2 * M_PI * n) + n * log10(n) - n * log10(M_E)));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll x;
    cin >> x;
    ll cnt = static_cast<ll>(log10(x) * x) + 1;
    ll l = 1, r = 1e12, ans;
    while (l <= r)
    {
        ll m = l + r >> 1;
        ll tmp = count(m);
        // cerr << m << " " << tmp << endl;
        if (tmp > cnt)
            r = m - 1,
            ans = m;
        else
            l = m + 1;
    }
    cout << ans << endl;
    return 0;
}
