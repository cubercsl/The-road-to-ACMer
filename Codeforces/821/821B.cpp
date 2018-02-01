#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll m, b;
    while (cin >> m >> b)
    {
        ll ans = 0;
        for (int i = 0; i <= b; i++)
        {
            ll x = m * (b - i);
            ll st = x * (x + 1) / 2;
            ll en = (2 * i + x) * (x + 1) / 2;
            ll tmp = (st + en) * (i + 1) / 2;
            ans = max(tmp, ans);
        }
        cout << ans << endl;
    }
}
