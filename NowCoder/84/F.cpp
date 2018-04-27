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

inline ll f(ll x) { return 1LL * (1 + x) * x / 2; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> v(n);
    for (auto& t : v) cin >> t;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(v.begin(), v.end(), v[i] + d) - v.begin() - 1;
        ans += f(pos - i - 1);
    }
    cout << ans << endl;
    return 0;
}
