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

void crt(ll r[], ll m[], ll n, ll &re, ll &mo)
{
    mo = 1, re = 0;
    for (int i = 0; i < n; i++) mo *= m[i];
    for (int i = 0; i < n; i++)
    {
        ll x, y, tm = mo / m[i];
        ll d = exgcd (tm, m[i], x, y);
        re = (re + tm * x * r[i]) % mo;
    }
    re = (re + mo) % mo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    ll m[] = {23, 28, 33};
    ll r[3], d;
    int k = 0;
    while (t--)
    {
        int kase = 0;
        if (k++)cout << endl;
        while ( cin >> r[0] >> r[1] >> r[2] >> d)
        {
            if (r[0] < 0) break;
            ll re, mo;
            crt(r, m, 3, re, mo);
            re -= d;
            if (re <= 0) re += mo;
            cout << "Case " << ++kase << ": the next triple peak occurs in " << re << " days." << endl;
        }
    }
    return 0;
}
