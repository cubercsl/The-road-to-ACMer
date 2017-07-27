// Pagodas, HDU5512

/*Sample Input
16
2 1 2
3 1 3
67 1 2
100 1 2
8 6 8
9 6 8
10 6 8
11 6 8
12 6 8
13 6 8
14 6 8
15 6 8
16 6 8
1314 6 8
1994 1 13
1994 7 12
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
    fastin
    int t, n, a, b;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        cout << "Case #" << ++kase << ": ";
        if (n / __gcd(a, b) & 1)
            cout << "Yuwgna" << endl;
        else
            cout << "Iaka" << endl;
    }
    return 0;
}
