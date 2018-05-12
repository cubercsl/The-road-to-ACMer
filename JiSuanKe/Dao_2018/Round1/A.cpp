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

int p;
ll s;
bool ok(int x, const vector<int>& v)
{
    ll now = 0;
    for (auto& t : v)
    {
        if (t > x)
            now += 1LL * (t - x) * p;
        else
            break;
        if (now > s) return false;
    }
    return now <= s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& t : v) cin >> t;
    sort(v.begin(), v.end(), greater<int>());
    cin >> p >> s;
    int l = 1, r = 20000, ans;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (ok(mid, v))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
