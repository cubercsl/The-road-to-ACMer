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
    vector<ll> a(14);
    ll ans = 0;
    for (auto& t : a) cin >> t;
    for (int i = 0; i < 14; i++)
    {
        vector<ll> b = a;
        ll x = b[i] / 14;
        ll y = b[i] % 14;
        b[i] = 0;
        for (int j = 0; j < 14; j++) b[(i + j + 1) % 14] += x;
        for (int j = 0; j < y; j++) b[(i + j + 1) % 14]++;
        ll tmp = 0;
        for (auto& t : b)
            if ((t & 1) == 0) tmp += t;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
