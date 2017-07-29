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

ll exgcd (ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b)
        d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else
        x = 1, y = 0;
    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int t;
    ll a, b;
    cin >> t;
    while (t--)
    {
        scanf("%lld/%lld", &a, &b);
        ll x, y;
        ll d = exgcd(a, b, x, y);
        if (d != 1)
        {
            cout << a / d << "/" << b / d << endl;
            continue;
        }
        if (a == 1)
        {
            cout << "1/" << b - 1 << endl;
            continue;
        }
        ll y1 = (-y + a) % a;
        ll y2 = (y + a) % a;
        ll x1 = (x + b) % b;
        ll x2 = (-x + b) % b;
        if (x1 > x2)
            cout << y1 << "/" << x1 << endl;
        else
            cout << y2 << "/" << x2 << endl;
    }
    return 0;
}
