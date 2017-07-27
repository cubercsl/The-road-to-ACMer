// Romantic, HDU2669

/*Sample Input
77 51
10 44
34 79
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

#define Mod(a,b) ((a)%(b)+(b)%(b))
ll exgcd(ll a, ll b, ll &x, ll &y)
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
    ll a, b, x, y;
    while (cin >> a >> b)
    {
        ll d = exgcd(a, b, x, y);
        if (d != 1)
            cout << "sorry" << endl;
        else
        {
            while (x <= 0)
                x += b, y -= a;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
