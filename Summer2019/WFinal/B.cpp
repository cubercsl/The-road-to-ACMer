#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll x)
{
    int ans = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            ans = min(ans, i);
    // cerr << x << ' ' << ans << endl;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    ll ans = 0;
    if (n & 1)
        ans = min(solve(n), solve(n + 1 >> 1));
    else
        ans = min(solve(n >> 1), solve(n + 1));

    cout << (1LL * n * (n + 1) / 2) / ans << endl;
}