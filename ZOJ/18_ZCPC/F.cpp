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
// const int mod = 1e9 + 7;
const double eps = 1e-6;

const int mod = 1e9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<vector<ll> > s(32, vector<ll>(n + 1));
        for (int i = 1; i < 30; i++)
            for (int j = 1; j <= n; j++) s[i][j] = s[i][j - 1] + a[j] / i;
        ll ans = 0;
        for (int i = 1, p; i <= m; i++)
        {
            cin >> p;
            ll b = p;
            int l = 0, c = 1;
            while (l < n)
            {
                int r = upper_bound(a.begin(), a.end(), b) - a.begin() - 1;
                (ans += 1LL * (s[c][r] - s[c][l]) * i) %= mod;
                c++, b *= p;
                l = r;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
