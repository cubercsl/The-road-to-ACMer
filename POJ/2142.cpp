// The Balace, POJ2142

/*Sample Input
700 300 200
500 200 300
500 200 500
275 110 330
275 110 385
648 375 4002
3 1 10000
0 0 0
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
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

int exgcd(int a, int b, int &x, int &y)
{
    int g = a;
    if (!b)
        x = 1, y = 0;
    else
        g = exgcd(b, a % b, y, x), y -= x * (a / b);
    return g;
}

void solve(int a, int b, int d, int &x, int &y)
{
    int g = exgcd(a, b, x, y);
    x *= d / g;
    int k = b / g;
    x = (x % k + k) % k;
    y = abs((a * x - d) / b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int a, b, d;
    while (cin >> a >> b >> d, a + b + d)
    {
        // ax-by=d
        int x1, y1, x2, y2;
        solve(a, b, d, x1, y1);
        solve(b, a, d, y2, x2);
        if (x1 + y1 < x2 + y2)
            cout << x1 << " " << y1 << endl;
        else
            cout << x2 << " " << y2 << endl;
    }
    return 0;
}
