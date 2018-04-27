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
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    int m = (n + 1) / 2;
    for (int i = 0; i < m; i++) a[i] -= i;
    for (int i = m; i < n; i++) a[i] -= n - i - 1;
    map<int, int> M;
    for (int i = 0; i < n; i++) M[a[i]]++;
    int ans = 0;
    for (auto& t : M) ans = max(ans, t.Y);
    cout << n - ans << endl;
    return 0;
}
