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

const int maxn = 1 << 17;
int a[maxn];
vector<PII> v[maxn];
int dp[1005][1005];

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        for (int i = 0; i < maxn; i++)
            v[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = dp[i][j - 1] ^ a[j];
                v[dp[i][j]].pb(mp(i, j));
            }
        ll ans = 0;
        for (int i = 0; i < maxn; i++)
        {
            if (v[i].empty()) continue;
            sort(v[i].begin(), v[i].end());
            for (auto& t : v[i])
            {
                auto r = upper_bound(v[i].begin(), v[i].end(), mp(t.Y, INF));
                if (r == v[i].end()) continue;
                ans += (ll)(v[i].size() - (r - v[i].begin()));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
