// A sequence of numbers, HDU2817

/*Sample Input
2
1 2 3 5
1 2 4 5
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
const int mod = 200907;
const double eps = 1e-6;

ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1) t = (t * a % mod);
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    double a, b, c;
    int k;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> k;
        if ((a + c) == 2 * b)
        {
            ll a1 = (ll)a;
            ll d = (ll)(b - a);
            ll ans = (a1 % mod + (k - 1) % mod * (d % mod)) % mod;
            cout << ans << endl;
        }
        else
        {
            ll a1 = (ll)a;
            ll t1 = (ll)(a1 % mod);
            double q1 = b / a;
            ll q2 = (ll)q1;
            ll q = (q2 % mod);
            ll tmp = Pow(q, k - 1, mod);
            ll ans = (t1 * tmp) % mod;
            cout << ans << endl;
        }
    }
    return 0;
}
