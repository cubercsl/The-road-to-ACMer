#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main()
{
    ll a, b, c, n;
    ull t[3], cnt, ans;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
    cnt = (a == b && b == c) ? 6 : (a == b || a == c || b == c) ? 2 : 1;
    if (n & 1)
        t[0] = n, t[1] = n / 2, t[2] = n / 2 + 1;
    else
        t[0] = n, t[1] = n / 2 + 4, t[2] = n / 2 - 1;

    for (int i = 0; i < 3; i++)
    {
        ull g = __gcd(t[i], cnt);
        t[i] /= g;
        cnt /= g;
    }
    ans = t[0] * t[1] * t[2];
    printf("%llu\n", ans);
    return 0;
}