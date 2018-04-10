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

set<ll> s;
string ss;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (ll i = 1; i * i < 2e9; i++) s.insert(i * i);
    ll n;
    cin >> n;
    ss = to_string(n);
    int m = ss.length();

    int ans = INF;
    for (int i = 1; i < (1 << m); i++)
    {
        string t;
        for (int j = 0; j < m; j++)
            if (i >> j & 1) t.push_back(ss[j]);
        if (t[0] != '0')
        {
            ll tmp = stoll(t);
            if (s.find(tmp) != s.end()) ans = min(ans, m - __builtin_popcount(i));
        }
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}