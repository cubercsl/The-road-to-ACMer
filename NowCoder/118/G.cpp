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
    int n;
    while (cin >> n)
    {
        bool flag = 0;
        vector<string> v(n);
        for (auto& t : v) cin >> t;
        for (auto& t : v)
        {
            if (t[0] == 'O' && t[1] == 'O')
            {
                flag = 1;
                t[0] = t[1] = '+';
                break;
            }
            if (t[3] == 'O' && t[4] == 'O')
            {
                flag = 1;
                t[3] = t[4] = '+';
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            for (auto& t : v) cout << t << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
