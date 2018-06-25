#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    go();
    return 0;
}

/****************************************************************************************************/

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, a *= a)
        if (n & 1) t *= a;
    return t;
}

ll solve(int c, int n)
{
    if (n == 0) return 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += Pow(c, __gcd(i, n));
    if (n & 1)
        ans += n * Pow(c, n + 1 >> 1);
    else
        ans += n / 2 * (1 + c) * Pow(c, n >> 1);
    return ans / n / 2;
}

void go()
{
    int n;
    while(cin >> n, ~n)
        cout << solve(3, n) << endl;
}