// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int mod = 1e9 + 7;
ll my_pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
vector<int> fenjie(int m)
{
    vector<int> ret;
    for (ll i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            ret.pb(i);
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) ret.pb(m);
    return ret;
}

inline ll f1(ll n)
{
    return 1LL * n * (n + 1) % mod * (2LL * n + 1) % mod * my_pow(6, mod - 2) % mod;
}
inline ll f2(ll n)
{
    return 1LL * (1 + n) * n % mod * my_pow(2, mod - 2) % mod;
}
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        vector<int> fac = fenjie(m);
        int sz = fac.size();
        ll ans = f1(n) + f2(n);
        ans %= mod;

        ll up = 1 << sz;
        for (ll i = 1; i < up; i++)
        {
            int cnt = 0;
            ll val = 1;
            for (int k = 0; k < sz; k++)
                if (i & (1LL << k))
                {
                    cnt++;
                    val *= fac[k];
                }
            ll tmp = val * val % mod * f1(n / val) % mod + val * f2(n / val) % mod;
            tmp %= mod;
            if (cnt & 1)
                ans = (ans - tmp + mod) % mod;
            else
                ans = (ans + tmp) % mod;
        }
        printf("%lld\n", ans);
    }
}