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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int k = k1 + k2;
    vector<int> a(n), b(n);
    for (auto& t : a) cin >> t;
    for (auto& t : b) cin >> t;
    for (int i = 0; i < n; i++) a[i] = abs(a[i] - b[i]);
    for (int i = 0; i < k; i++)
    {
        int pos = 0;
        for (int i = 1; i < n; i++)
            if (a[i] > a[pos]) pos = i;
        a[pos] = abs(a[pos] - 1);
    }
    ll ans = 0;
    for (auto& t : a) ans += 1LL * t * t;
    cout << ans << endl;
    return 0;
}
