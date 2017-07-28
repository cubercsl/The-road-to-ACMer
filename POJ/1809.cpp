// Regetni, POJ1809

/*Sample Input
6
3 0 0 2 0 1 -3
3 0 0 2 1 1 -3
3 0 0 2 2 3 3
4 0 0 2 0 0 2 2 2
4 0 0 1 0 0 1 1 1
9 0 0 0 1 0 2 1 0 1 1 1 2 2 0 2 1 2 2
*/

#include <iostream>
#include <cstring>
#include <vector>
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

ll C (int m, int n)
{
    if (m < n) return 0;
    if (m == n || n == 0)  return 1;
    ll ans = 1;
    for (int i = 1, j = m; i <= n; i++, j--)
        ans = ans * j / i;
    return ans;
}

int a[4];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    fastin
    int t, n, x, y;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        clr(a, 0);
        while (n--)
        {
            cin >> x >> y;
            if ((x & 1) && (y & 1)) a[0]++;        // oo
            else if (!(x & 1) && !(y & 1)) a[1]++; // ee
            else if ((x & 1) && !(y & 1)) a[2]++;  // oe
            else a[3]++;                           // eo
        }
        ll ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans += C(a[i], 3);
            ll sum = 0;
            for (int j = 0; j < 4; j++)
                if (j != i)
                    sum += a[j];
            ans += C(a[i], 2) * sum;
        }
        cout << "Scenario #" << ++kase << ":" << endl;
        cout << ans << endl;
    }

    return 0;
}
