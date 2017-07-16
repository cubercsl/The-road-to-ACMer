//  Play with Floor and Ceil, UVa10673

/*Sample Input
3
5 2
40 2
24444 6
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

ll exgcd(ll a, ll b, ll &x, ll&y)
{
    ll d = a;
    if (!b) x = 1, y = 0;
    else d = exgcd(b, a % b, y, x), y -= x * (a / b);
    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll c, k, x, y;
        cin >> c >> k;
        ll a = floor(1.0 * c / k);
        ll b = ceil(1.0 * c / k);
        ll d = exgcd(a, b, x, y);
        x *= c / d;
        y *= c / d;
        cout << x << " " << y << endl;
    }
    return 0;
}
