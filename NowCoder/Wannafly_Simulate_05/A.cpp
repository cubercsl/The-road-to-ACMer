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
    ll t;
    while (cin >> n >> t)
    {
        ll ans = 0;
        while (n--)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            ll k = x + y;
            ll b = k * 2 - z;
            if (z == 0)
            {
                ll val = t / k;
                ll tmp = val * k;
                ans += val * y;
                if (t - tmp > x) ans += t - tmp - x;
                continue;
            }
            ll val = (-b + sqrt(b * b + 8 * z * t)) / (2 * z);
            ll tmp = y * val + (val - 1) * val * z / 2;
            ans += tmp;
            tmp += val * x;
            if (t - tmp > x) ans += t - tmp - x;
        }
        cout << ans << endl;
    }
    return 0;
}