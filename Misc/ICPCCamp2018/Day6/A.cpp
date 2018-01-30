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
const int maxn = 1e5 + 5;

ll dp[maxn];
ll ans;
vector<int> G[maxn];
// ll F[maxn];
ll C[maxn][4];

void CalComb()
{
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= 3; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

ll my_pow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    CalComb();
    while (cin >> n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans = 0;

        ans = (C[n][2] + n) % mod;
        for (int i = 1; i <= n; i++) {
            ll cnt = G[i].size();
            if (cnt > 2) ans = (ans + C[cnt][3]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}