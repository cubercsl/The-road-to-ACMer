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
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

ll Mul(ll a, ll b, ll mod)
{
    a %= mod;
    ll t = 0;
    for (; b; b >>= 1, a = (a << 1) % mod)
        if (b & 1) t = (t + a) % mod;
    return t;
}
ll Pow(ll a, ll n, ll mod)
{
    a %= mod;
    ll t = 1;
    for (; n; n >>= 1, a = Mul(a, a, mod))
        if (n & 1) t = Mul(t, a, mod);
    return t;
}

bool Miller_Rabin(ll n, int s)
{
    if (n == 2) return 1;
    if (n < 2 || !(n & 1)) return 0;
    int t = 0;
    ll u = n - 1;
    while ((u & 1) == 0) t++, u >>= 1;
    for (int i = 0; i < s; i++)
    {
        ll a = rand() % (n - 1) + 1;
        ll x = Pow(a, u, n);
        for (int j = 0; j < t; j++)
        {
            ll y = Mul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return 0;
            x = y;
        }
        if (x != 1) return 0;
    }
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        if (n == 4)
            cout << 2 << " " << 2 << endl;
        else
        {
            for (ll i = 3;; i += 2)
            {
                if (Miller_Rabin(i, 10) && Miller_Rabin(n - i, 10))
                {
                    cout << i << " " << n - i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
