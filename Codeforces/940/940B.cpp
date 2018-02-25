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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if (k == 1)
    {
        cout << a * (n - 1) << endl;
        return 0;
    }
    ll ans = 0;
    while (n > 1)
    {
        if (n % k == 0)
            ans += min(a * (n - n / k), b), n /= k;
        else
        {
            if (n < k)
                ans += a * (n - 1), n = 1;
            else
                ans += a * (n - (n / k) * k), n = n / k * k;
        }
    }
    cout << ans << endl;
    return 0;
}