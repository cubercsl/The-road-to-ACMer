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

const int N = 1 << 17;
map<int, int> dp[N];

int gao(int a, int w)
{
    auto it = dp[a].lower_bound(w);
    if (it == dp[a].begin()) return 1;
    --it;
    return it->second + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (m--)
    {
        static int a, b, w;
        cin >> a >> b >> w;
        int v = gao(a, w);
        if (gao(b, w + 1) > v) continue;
        dp[b][w] = max(dp[b][w], v);
        for (auto it = dp[b].upper_bound(w); it != dp[b].end() && it->second <= v; it = dp[b].erase(it)) ;
        ans = max(ans, v);
    }
    cout << ans << endl;

    return 0;
}
