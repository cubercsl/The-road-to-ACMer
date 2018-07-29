#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1 << 20;
bool is_prime_small[maxn], is_prime[maxn];
int segment_sieve(ll a, ll b)
{
    int tot = 0;
    for (ll i = 0; i * i < b; ++i)
        is_prime_small[i] = true;
    for (ll i = 0; i < b - a; ++i)
        is_prime[i] = true;
    for (ll i = 2; i * i < b; ++i)
        if (is_prime_small[i])
        {
            for (ll j = 2 * i; j * j < b; j += i)
                is_prime_small[j] = false;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
                is_prime[j - a] = false;
        }
    for (ll i = 0; i < b - a; ++i)
        if (is_prime[i]) ++tot;
    return tot;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        printf("Case %d: %d\n", ++kase, segment_sieve(a, b + 1) - (a == 1));
    }
}