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
    int T;
    cin >> T;
    while (T--)
    {
        double l, v1, v2;
        int n, k;
        cin >> n >> l >> v1 >> v2 >> k;
        int t = (n + k - 1) / k;
        double t2 = l / (v2 * t - (v2 - v1) / (v1 + v2) * (t - 1) * v2);
        double t1 = (l - t2 * v2) / v1;
        cout << fixed << setprecision(10) << t1 + t2 << endl;
    }
    return 0;
}
