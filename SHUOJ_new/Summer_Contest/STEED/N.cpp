#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

ll Mul (ll a, ll b, ll m)
{
    ll t = 0;
    for (; b; b >>= 1, a = (a << 1) % m)
        if (b & 1) t = (t + a) % m;
    return t;
}

ll Pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, a = Mul(a, a, m))
        if (n & 1) t = Mul(t, a, m);
    return t;
}

ll exgcd (ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b)
        d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else
        x = 1, y = 0;
    return d;
}

ll inv(ll a, ll m)
{
    ll x, y;
    ll d = exgcd(a, m, x, y);
    return d == 1 ? (x % m + m) % m : -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll e, p, q, n, a[105];
        scanf("%lld%lld%lld%lld", &e, &p, &q, &n);
        ll m = p * q;
        ll d = inv(e, (p - 1) * (q - 1));
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for (int i = 0; i < n; i++)
        {
            if (i)
                putchar(' ');
            printf("%lld", Pow(a[i], d, m));
        }
        putchar('\n');
    }
    return 0;
}
