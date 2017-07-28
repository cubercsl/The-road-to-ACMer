// Puzzle, 2017 Multi-University Training Contest, HDU6048

/*Sample Input
3
3 2 3
3 2 4
999 999 1
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
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    int n, m, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> p;
        int num = n * m - 1;
        int cnt = 0;
        while (num > p)
        {
            int t = (num - 1) / p + 1;
            cnt += t * (t - 1) / 2 * (p - 1);
            num -= t;
        }
        if (cnt & 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
