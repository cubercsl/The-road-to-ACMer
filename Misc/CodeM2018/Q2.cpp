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
    int n, m, k;
    cin >> n >> m >> k;
    assert(m <= n);
    vector<PII> v(k);
    int ans = -INF, id = -1;
    for (auto& t : v) cin >> t.X >> t.Y;
    for (int i = 0; i < k; i++)
    {
        int tmp = m * v[i].X + (n - m) * v[i].Y;
        if (tmp > ans) tmp = ans, id = i;
    }
    assert(~id);
    for (int i = 0; i < k; i++) printf("%d%c", i == id ? n : 0, " \n"[i == k - 1]);
    return 0;
}