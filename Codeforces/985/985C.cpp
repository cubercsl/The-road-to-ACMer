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
    int n, k, l;
    cin >> n >> k >> l;
    vector<ll> a(n * k);
    for (auto& t : a) cin >> t;
    sort(a.begin(), a.end());
    if (a[n - 1] - a[0] > l) return cout << 0 << endl, 0;
    vector<ll> b;
    for (int i = 0; i < n * k; i++)
    {
        if (a[i] - l <= a[0])
            b.pb(a[i]);
        else
            break;
    }
    ll ans = 0;
    int j = 0, m = b.size();
    for (int i = n; i; i--)
    {
        ans += b[j];
        j += k;
        j = min(j, m - i + 1);
    }
    cout << ans << endl;
    return 0;
}
