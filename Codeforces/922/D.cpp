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
    ll ans = 0;
    vector<PII> v(n);
    for (int i = 0; i < n; i++)
    {
        static string s;
        cin >> s;
        int t = 0;
        for (auto& c : s)
        {
            if (c == 's')
                ++t, ++v[i].X;
            else
                ans += t, ++v[i].Y;
        }
    }
    sort(v.begin(), v.end(), [](const PII& a, const PII& b) {
        return 1LL * a.Y * b.X < 1LL * a.X * b.Y;
    });
    ll tmp = 0;
    for (auto& t : v) ans += tmp * t.Y, tmp += t.X;
    cout << ans << endl;
    return 0;
}
