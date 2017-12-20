#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

ll Pow(ll a, ll b)
{
    ll ret = 1;
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (ret *= a) %= mod;
    return ret;
}

map<ll, ll> MP;
ll dfs(ll n)
{
    if (MP[n]) return MP[n];
    ll tmp = Pow(2, n - 1);
    for (ll d = 2; d * d <= n; d++)
        if (n % d == 0)
        {
            (tmp -= dfs(n / d)) %= mod;
            if (d * d != n) (tmp -= dfs(d)) %= mod;
        }
    if (n != 1) (tmp -= MP[1]) %= mod;
    return MP[n] = tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll x, y;
    while (~scanf("%lld%lld", &x, &y))
    {
        MP[1] = 1;
        MP[2] = 1;
        if (y % x != 0)
        {
            puts("0");
            continue;
        }
        printf("%lld\n", (dfs(y / x) + mod) % mod);
    }
    return 0;
}