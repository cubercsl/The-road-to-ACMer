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
    long long k, d, t;
    cin >> k >> d >> t;
    double p = ((k - 1) / d + 1) * d;
    double tmp = (ll)(2LL * t / (p + k));
    double ans = tmp * p;
    double rest = 2LL * t - (p + k) * tmp;
    if (rest < 2 * k)
        ans += rest / 2;
    else
        ans += k, ans += rest - 2 * k;
    printf("%.1f\n", ans);
    return 0;
}