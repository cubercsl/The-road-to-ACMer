// Not so Mobile, Uva839

/*Sample Input
1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2
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

bool solve(int &w)
{
    int w1, d1, w2, d2;
    bool b1 = true, b2 = true;
    cin >> w1 >> d1 >> w2 >> d2;
    if (!w1) b1 = solve(w1);
    if (!w2) b2 = solve(w2);
    w = w1 + w2;
    return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t, w;
    cin >> t;
    while (t--)
    {
        if (solve(w))cout << "YES" << endl;
        else
            cout << "NO" << endl;
        if (t)cout << endl;
    }
    return 0;
}
