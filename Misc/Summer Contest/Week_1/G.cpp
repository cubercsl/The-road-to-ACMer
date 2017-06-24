#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(ll x)
{
    ll a = 0;
    ll q = x;
    while (x != 0)
    {
        a += x % 10;
        x /= 10;
    }
    return q - a;
}

ll solve(ll l, ll r, ll x)
{
    ll mid;
    while (l < r)
    {
        mid = l + (r - l) / 2  ;
        if (sum(mid) >= x)
            r = mid ;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    ll n, m, a;
    while (cin >> n >> m)
    {
        ll a = solve(1, n + 1, m);
        cout << n - a + 1 << endl;
    }
    return 0;
}
