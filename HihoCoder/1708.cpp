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
ll n, m, x, y, a, b, c, d;
ll ans = 0;
ll solve(ll n, ll m, ll a, ll b)
{
    if (a == 0) return m / b;
    if (b == 0) return n / a;
    return min(n / a, m / b);
}
ll gao(ll n, ll m, ll a, ll b, int op = 1)
{
    if (a > 0 && b >= 0)
        ans += solve(n - x, m - y, a, b) * op;
    else if (a > 0 && b < 0)
        ans += solve(n - x, y - 1, a, b) * op;
    else if (a <= 0 && b > 0)
        ans += solve(x - 1, m - y, a, b) * op;
    else
        ans += solve(x - 1, y - 1, a, b) * op;
}
inline int sgn(ll x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m >> x >> y;
    cin >> a >> b >> c >> d;
    gao(n, m, a, b);
    gao(n, m, c, d);
    if (sgn(a) == sgn(c) && sgn(b) == sgn(d))
    {
        if (a * d == b * c) gao(n, m, a * c / __gcd(a, c), b * d / __gcd(b, d), -1);
    }
    cout << ans + 1 << endl;
    return 0;
}