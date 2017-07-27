// The Monkey King, HDU5201

/*Sample Input
2
2 2
3 5
*/

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

const int maxn = 2e5 + 5;
ll f[maxn], inv[maxn];

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a) % mod)
        if (n & 1) t = (t * a) % mod;
    return t;
}

void init()
{
    inv[0] = f[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        f[i] = (i * f[i - 1]) % mod;
        inv[i] = Pow(f[i], mod - 2);
    }
}

ll C (ll n, ll m)
{
    if (n < m || n < 0 || m < 0) return 0;
    return f[n] * inv[m] % mod * inv[n - m] % mod;
}

ll F(ll a, ll b)
{
    return C(a + b - 1, a);
}

int main()
{
    fastin
    init();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        ll ans = 0;
        cin >> n >> m;
        if (n == 1 || m == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans + F(n - i, m - 1)) % mod;
            for (ll j = 1; n - (j + 1) * i >= 0; j++)
            {
                ll tmp = C(m - 1, j) * F(n - (j + 1) * i, m - 1) % mod;
                if (j % 2) ans = (ans - tmp + mod) % mod;
                else ans = (ans + tmp) % mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
