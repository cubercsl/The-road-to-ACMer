// Least Common Multiple, HDU1019
 
/*Sample Input
2
3 5 7 15
6 4 10296 936 1287 792 1
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a;
        cin >> n;
        n--;
        cin >> a;
        ll ans = a;
        while (n--)
        {
            cin >> a;
            ll tmp = __gcd(a, ans);
            ans = (a * ans) / tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
