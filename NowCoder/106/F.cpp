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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    if (k == 0)
    {
        vector<int> b = a;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            if (a[i] != b[i]) return cout << i + 1 << endl, 0;
        return cout << -1 << endl, 0;
    }
    vector<vector<int> > v(k);
    int p = 0;
    for (auto& t : a) v[p].push_back(t), ++p %= k;
    for (auto& t : v) sort(t.begin(), t.end());
    sort(a.begin(), a.end());
    int ans = -1;
    for (int i = 0; i < n; i++)
        if (a[i] != v[i % k][i / k])
        {
            ans = i + 1;
            break;
        }
    cout << ans << endl;
    return 0;
}
