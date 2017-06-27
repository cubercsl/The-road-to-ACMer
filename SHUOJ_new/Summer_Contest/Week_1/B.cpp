#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll s, n;
    while (cin >> s >> n)
    {
        ll limit = (1 + n) * n / 2;
        ll ans = -1;
        for (ll i = 1; i * i <= s; i++)
            if (s % i == 0)
            {
                if (i >= limit)
                    ans = max(ans, s / i);
                if (s / i >= limit)
                    ans = max(ans, i);
            }
        cout << ans << endl;
    }
    return 0;
}
