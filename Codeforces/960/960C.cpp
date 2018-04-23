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
    vector<ll> v;
    int x, d;
    cin >> x >> d;
    for (ll p = 1; x; p += d + 1)
    {
        int t = 0, c = 0;
        while ((t << 1 | 1) <= x) t = (t << 1 | 1), c++;
        for (int i = 0; i < c; i++) v.push_back(p);
        x -= t;
    }
    cout << v.size() << endl;
    for (auto& t : v) cout << t << " ";
    return 0;
}
