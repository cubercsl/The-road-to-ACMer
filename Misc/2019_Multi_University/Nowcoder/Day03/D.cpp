#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
ll Pow(__int128 a, ll n, ll mod)
{
    __int128 t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll euler(ll n)
{
    ll rt = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            rt -= rt / i;
            while (n % i == 0) n /= i;
        }
    if (n > 1) rt -= rt / n;
    return rt;
}

ll p, n, m;
ll result;

std::vector<std::pair<ll, int>> fff;

std::vector<std::pair<ll, int>> frac(ll x) {

    std::vector<std::pair<ll, int>> result;
    if(x <= 1) return {};
    if(!(x % 2)) {
        
        int count = 0;
        do { x /= 2; ++count; } while(!(x % 2));
        result.push_back(std::pair<ll, int>(2, count));

    }
    for(ll i = 3; i * i <= x; i += 2) {

        if(x % i) continue;
        int count = 0;
        do { x /= i; ++count; } while(!(x % i));
        result.push_back(std::pair<ll, int>(i, count));

    }
    if(x > 1) result.push_back(std::pair<ll, int>(x, 1));
    return result;

}

int gao(ll n, ll x)
{ // n以内与x互质的数的个数
    int ret = 0;
    auto d = frac(x);
    for (int i = 0; i < (1 << d.size()); i++)
    {
        int tmp = 1;
        for (int j = 0; j < d.size(); j++)
            if (i >> j & 1) tmp *= d[j].first;
        if (__builtin_parity(i)) tmp *= -1;
        ret += n / tmp;
    }
    return ret;
}
void dfs(int index = 0, int count = m, ll value = 1) {

    if(index == int(fff.size())) {
        
        //std::cout << value << ' ' << count << ' ' << gao(n / value, value) << std::endl;
        result += ll(count) * gao(n / value, value);
        return;

    }
    ll x = fff[index].first;
    int c = fff[index].second;
    for(int i = 1; ; ++i) {
        
        value *= x;
        if(value > n) break;
        int y = int(m) - (c - 1) / i;
        if(y <= 0) continue;
        dfs(index + 1, std::min(count, y), value);

    }

}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &p, &n, &m);
        if(__gcd(p * 9ll, 10ll) != 1) std::puts("0");
        else {
            
            ll phi = euler(p * 9LL);
            ll xx = 1e18;
            for (ll i = 1; i * i <= phi; i++)
            {
                if(phi % i) continue;
                if (Pow(10, i, p * 9LL) == 1)
                {
                    xx = min(xx, i);
                }
                if (Pow(10, phi / i, p * 9LL) == 1)
                {
                    xx = min(xx, phi / i);
                }
            }
            result = 0;
            //std::cout << phi << std::endl;
            //std::cout << xx << std::endl;
            //if(xx < n) result += ll(n - xx) / xx * m;
            fff = frac(xx);
            dfs();
            std::printf("%lld\n", result);

        }

    }
}