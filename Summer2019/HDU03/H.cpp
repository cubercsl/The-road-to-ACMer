#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
    long long n, k;
    int kase = 0;
    while (~scanf("%lld%lld", &n, &k))
        printf("Case #%d: %lld\n", ++kase, Pow(n % mod, k));
}