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
    cin >> n >> m;
    vector<PII> a(n), b(m);
    for (auto& t : a) cin >> t.X >> t.Y;
    for (auto& t : b) cin >> t.X >> t.Y;
    double ans = 1e18, sum = 0;
    for (auto& t : a) sum += t.X;
    for (auto& t : b)
        if (sum >= t.X) ans = min(ans, sum - t.Y);
    for (int i = 1; i < (1 << n); i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j].Y == 1 && (i >> j & 1))
                sum += a[j].X * 0.8;
            else
                sum += a[j].X;
        }
        ans = min(ans, sum);
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}