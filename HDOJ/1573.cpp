// X问题, HDU1573

/*Sample Input
3
10 3
1 2 3
0 1 2
100 7
3 4 5 6 7 8 9
1 2 3 4 5 6 7
10000 10
1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 6 7 8 9
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


ll exgcd(ll a, ll b, ll &x, ll &y)
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
        if ((r[i] - re) % d != 0) return 0;
        x = (r[i] - re) / d * x % (m[i] / d);
        re += x * mo;
        mo = mo / d * m[i];
        re %= mo;
    }
    re = (re + mo) % mo;
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll a[15], b[15];
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        ll n;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        ll re, mo;
        if (excrt(b, a, m, re, mo))
        {
            if (n < re)
                cout << 0 << endl;
            else
            {
                ll ans = (n - re) / mo;
                if (re <= n && re != 0)
                    ans++;
                cout << ans << endl;
            }
        }
        else
            cout << 0 << endl;
    }
    return 0;
}
