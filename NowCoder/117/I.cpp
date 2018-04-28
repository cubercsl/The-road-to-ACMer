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
    fastin
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        ll k, ans = 0;
        int d = 0, m = 0;
        cin >> n >> k;
        char c;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == 'M')
                ans += d, m++;
            else
                d++;
        }
        ll mm = d * m;
        if (k <= mm)
            cout << abs(ans - k) << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
