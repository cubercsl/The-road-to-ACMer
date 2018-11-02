#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, x, y;
    while(~scanf("%lld%lld%lld%lld",&a,&b,&x,&y))
    {
        ll g = __gcd(x, y);
        x /= g, y /= g;
        a /= x, b /= y;
        printf("%lld\n", min(a, b));
    }
    return 0;
}