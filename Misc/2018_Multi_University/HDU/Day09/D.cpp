#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll a, b, c, _a, _b, _c;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &_a, &_b, &_c);
        ll x = _a * (c - b) + _b * (a - c) + _c * (b - a);
        ll y = a + b + c;
        ll d = __gcd(x, y);
        x /= d, y /= d;
        if (y < 0) x = -x, y = -y;
        if (y == 1)
            printf("%lld\n", x);
        else
            printf("%lld/%lld\n", x, y);
    }
    return 0;
}