// Hello Kiki. HDU3579

/*Sample Input
2
2
14 57
5 56
5
19 54 40 24 80
11 2 36 20 76
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

const int maxn = 8;

ll exgcd (ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b)
        d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else
        x = 1, y = 0;
    return d;
}

bool excrt(ll r[], ll m[], ll n, ll &re, ll &mo)
{
    ll x, y;
    mo = m[0], re = r[0];
    for (int i = 1; i < n; i++)
    {
        ll d = exgcd(mo, m[i], x, y);
        if ((r[i] - re) % d != 0) return false;
        x = (r[i] - re) / d * x % (m[i] / d);
        re += x * mo;
        mo = mo / d * m[i];
        re %= mo;
    }
    re = (re + mo) % mo;
    return true;
}

int main()
{
    int t, n;
    int kase = 0;
    ll re, mo;
    cin >> t;
    ll r[maxn], m[maxn];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> m[i];
        for (int i = 0; i < n; i++)
            cin >> r[i];
        cout << "Case " << ++kase << ": ";
        if (excrt(r, m, n, re, mo))
        {
            if (re)
                cout << re << endl;
            else
                cout << mo << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
