#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, b;
    cin >> n >> b;
    map<ll, int> cnt;
    for (ll a = 2; a * a <= b; a++)
    {
        while (b % a == 0)
        {
            b /= a;
            cnt[a]++;
        }
    }
    if (b != 1) cnt[b]++;
    ll ans = n + 10;
    for (auto t : cnt)
    {
        ll tmp = n;
        ll now = 0;
        ll x = t.first;
        while (tmp > 0)
        {
            tmp /= x;
            now += tmp;
        }
        ans = min(ans, now / t.second);
    }
    cout << ans << endl;
}
