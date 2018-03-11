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
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> x(n), y(m);
        for (auto& t : x) cin >> t;
        for (auto& t : y) cin >> t;
        int ans = 0;
        ll a = 0, b = 0;
        for (int i = 0, j = 0; i < n || j < m;)
        {
            if (a > b && j < m)
                b += y[j++];
            else if (a < b && i < n)
                a += x[i++];
            else if (a == b)
            {
                ans++;
                if (i < n)
                    a += x[i++];
                else
                    b += y[j++];
            }
        }
        cout << ans << endl;
    }
    return 0;
}