#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void go(ll l, ll r, ll& n)
{
    if (l < r)
    {
        ll k = (r - l + 1) / 2;
        if (n < l + k)
            go(l, l + k - 1, n);
        else
            go(l + k, r, n);
        n = l + r - n;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll x, n;
        scanf("%lld%lld", &x, &n);
        go(1, x, n);
        printf("%lld\n", n);
    }
}