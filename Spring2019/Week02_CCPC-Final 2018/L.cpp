#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> dic;

bool isprime(ll x)
{
    if (dic.count(x)) return dic[x];
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0) return dic[x] = 0;
    return dic[x] = (x != 1);
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("Case %d: ", ++kase);
        if (n < 12)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        if (n % 2 == 0)
        {
            n -= 8;
            for (ll i = 2; i <= n; i++)
            {
                if (isprime(i) && isprime(n - i))
                {
                    printf("2 2 2 2 %lld %lld\n", i, n - i);
                    break;
                }
            }
        }
        else
        {
            n -= 9;
            for (ll i = 2; i <= n; i++)
            {
                if (isprime(i) && isprime(n - i))
                {
                    printf("2 2 2 3 %lld %lld\n", i, n - i);
                    break;
                }
            }
        }
    }
}
