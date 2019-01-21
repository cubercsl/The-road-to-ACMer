#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
bool vis[maxn];
int tot, prime[maxn];
void CalPhi()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > maxn) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
void solve(ll a, ll b)
{
    ll x = __gcd(a, b);
    if (x == 1)
    {
        puts("1");
        printf("%lld %lld\n", a, b);
        return;
    }
    //cout << a << b << endl;
    if (a == b)
    {
        //cout << 1 << endl;
        for (int i = 0; i < tot && prime[i] < a; i++)
        {
            if (__gcd(1LL * prime[i], a - prime[i]) == 1)
            {
                puts("2");
                //cout << prime[i] << endl;
                ll ans = a - prime[i];
                //cout << ans <<endl;
                printf("%d %lld\n", prime[i], ans);
                printf("%lld %d\n", ans, prime[i]);
                return;
            }
        }
        puts("-1");
        return;
    }
    //cout << a << b << endl;
    //cout << 2 << endl;
    ll a1 = a / x, b1 = b / x;
    if (a1 != 1 && b1 != 1)
    {
        ll tmp = x - 1;
        if (__gcd(a1, tmp) == 1 && __gcd(b1, tmp) == 1)
        {
            puts("2");
            printf("%lld %lld\n", a1, b1 * tmp);
            printf("%lld %lld\n", a1 * tmp, b1);
            return;
        }
    }

    for (int i = 0; i < tot && prime[i] < x; i++)
    {
        if (x % prime[i] == 0) continue;
        if (__gcd(a1, 1LL * prime[i]) == 1 && __gcd(b1, 1LL * prime[i]) == 1)
        {
            ll tmp = x - prime[i];
            if (__gcd(a1, tmp) == 1 && __gcd(b1, tmp) == 1)
            {
                puts("2");
                printf("%lld %lld\n", a1 * prime[i], b1 * tmp);
                printf("%lld %lld\n", a1 * tmp, b1 * prime[i]);
                return;
            }
        }
    }
    ll mi = min(a, b);
    for (int i = 0; i < tot && prime[i] < mi; i++)
    {
        if (a % prime[i] == 0 || b % prime[i] == 0) continue;
        ll ta = a - prime[i], tb = b - prime[i];
        if (__gcd(ta, tb) == 1)
        {
            puts("2");
            printf("%d %lld\n", prime[i], tb);
            printf("%lld %d\n", ta, prime[i]);
            return;
        }
    }
    puts("-1");
    return;
}
int main()
{
    CalPhi();
    int T;
    ll a, b;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &a, &b);
        solve(a, b);
    }
}