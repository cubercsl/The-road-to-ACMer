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
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto& t : a) cin >> t;
    for (auto& t : b) cin >> t;
    ll ans = 0;
    for (int i = n - 1; i; i--)
        if (a[i] > b[i]) ans += (a[i] - b[i]), a[i - 1] += a[i] - b[i], a[i] = b[i];
    for (int i = 0; i + 1 < n; i++)
        if (a[i] > b[i]) ans += (a[i] - b[i]), a[i + 1] += a[i] - b[i], a[i] = b[i];
    cout << ans << endl;
    return 0;
}
