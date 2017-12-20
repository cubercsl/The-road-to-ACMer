#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
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
    int h1, a1, c1, h2, a2;
    while (cin >> h1 >> a1 >> c1 >> h2 >> a2)
    {
        vector<int> v;
        while (h2 > 0)
        {
            if (h1 - a2 > 0 || h2 - a1 <= 0)
            {
                v.pb(0);
                h2 -= a1;
                h1 -= a2;
            }
            else
            {
                v.pb(1);
                h1 += c1;
                h1 -= a2;
            }
        }
        cout << v.size() << endl;
        for (auto c : v)
            puts(c ? "HEAL" : "STRIKE");
    }
    return 0;
}
