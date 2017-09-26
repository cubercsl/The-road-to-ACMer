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

int solve(ll a, ll b, ll f, ll k)
{
    vector<ll> v;
    int cnt = 0;
    ll cur = 0;
    ll d = a - f;
    for (int i = 1; i <= k; i++)
    {
        if (i & 1)
        {
            cur += f;
            v.pb(cur);
            cur += d;
        }
        else
        {
            cur += d;
            v.pb(cur);
            cur += f;
        }
    }
    v.pb(cur);
    cur = b;
    // if (b < f || b < 2 * f || b < 2 * d) return -1;
    ll now = 0;
    for (auto& t : v)
    {
        // cout << t - now << " " << cur << endl;
        if (t - now > cur)
            cnt++, cur = b;
        cur -= (t - now);
        if (cur < 0) return -1;
        now = t;
    }
    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    ll a, b, f, k;
    while (cin >> a >> b >> f >> k)
        cout << solve(a, b, f, k) << endl;
    return 0;
}
