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

ll Euler(ll n)
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

ll Pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % m))
        if (n & 1) t = (t * a % m);
    return t;
}

ll solve(ll n, ll m)
{
    if (m == 1) return 0;
    ll ans = 1;
    if (n <= 5)
    {
        for (int i = 1; i <= n; i++)
            ans = Pow(i, ans, m);
        return ans;
    }
    else
    {
        ll phi = Euler(m);
        ll z = solve(n - 1, phi);
        ans = Pow(n, phi + z, m);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", solve(n, m));
    return 0;
}
