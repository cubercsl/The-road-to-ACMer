#include <bits/stdc++.h>
using namespace std;

typedef __int128 LL;
typedef long long ll;
namespace math
{
LL q1, q2, w;

struct P
{ // x + y * sqrt(w)
    LL x, y;
};

P pmul(const P& a, const P& b, LL p)
{
    P res;
    res.x = (a.x * b.x + a.y * b.y % p * w) % p;
    res.y = (a.x * b.y + a.y * b.x) % p;
    return res;
}
LL bin(LL a, LL n, LL p)
{
    LL t = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1) (t *= a) %= p;
    return t;
}
P bin(P x, LL n, LL MOD)
{
    P ret = {1, 0};
    for (; n; n >>= 1, x = pmul(x, x, MOD))
        if (n & 1) ret = pmul(ret, x, MOD);
    return ret;
}
LL Legendre(LL a, LL p) { return bin(a, (p - 1) >> 1, p); }

LL equation_solve(LL b, LL p)
{
    if (p == 2) return 1;
    if ((Legendre(b, p) + 1) % p == 0)
        return -1;
    LL a;
    while (true)
    {
        a = rand() % p;
        w = ((a * a - b) % p + p) % p;
        if ((Legendre(w, p) + 1) % p == 0)
            break;
    }
    return bin({a, 1}, (p + 1) >> 1, p).x;
}

} // namespace math

typedef long long ll;
ll a[1 << 17];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        ll p;
        scanf("%d%lld", &n, &p);
        map<ll, int> cnt;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", a + i);
            if (a[i]) cnt[a[i]]++;
        }
        if (p == 2)
        {
            puts("0");
            continue;
        }
        if (p == 3)
        {
            ll ans = 0;
            ans += cnt[1] * (cnt[1] - 1) / 2;
            ans += cnt[2] * (cnt[2] - 1) / 2;
            printf("%lld\n",ans);
            continue;
        }
        ll sqrt_m3 = math::equation_solve(p - 3, p);
        if (sqrt_m3 == -1)
        {
            puts("0");
            continue;
        }
        LL x = math::bin(2, p - 2, p) * (-1 + sqrt_m3) % p;
        LL y = math::bin(2, p - 2, p) * ((-1 - sqrt_m3 + p) % p) % p;
        // cerr << (ll)x << ' ' << (ll)y << endl;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!a[i]) continue;
            cnt[a[i]]--;
            ll tx = a[i] * x % p;
            ll ty = a[i] * y % p;
            if (tx != ty)
            {
                if (cnt.count(tx)) ans += cnt[tx];
                if (cnt.count(ty)) ans += cnt[ty];
            }
            else
            {
                if (cnt.count(tx)) ans += cnt[tx];
            }
            cnt[a[i]]++;
        }
        printf("%lld\n", ans / 2);
    }
}