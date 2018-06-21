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
    vector<int> d(n);
    vector<PII> ans;
    for (auto& t : d) cin >> t;
    function<void(int, int, int, int)> solve = [&](int l, int r, int vl, int vr) {
        if (l > r) return;
        if (l == r)
        {
            for (int i = vr; i > vl; i--)
                for (int j = vl; j < i; j++) ans.push_back({i, j});
            return;
        }
        int w = d[l];
        for (int i = vr; i > vr - w; i--)
            for (int j = vl; j < i; j++) ans.push_back({i, j});
        int nl = vl + d[r] - d[r - 1], nr = vr - d[l];
        for (int i = r; i >= l; i--) d[i] -= d[l];
        solve(l + 1, r - 1, nl, nr);
    };
    solve(0, n - 1, 1, d[n - 1] + 1);
    cout << ans.size() << endl;
    for (auto& t : ans) cout << t.X << " " << t.Y << endl;
    return 0;
}
