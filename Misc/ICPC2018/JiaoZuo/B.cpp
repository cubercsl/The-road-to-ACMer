// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e3 + 5;
ll dp[maxn][10][2];
int a[maxn];
char f[maxn];

inline ll cal(ll a, char b, ll c) {
    if (b == '+') {
        return a + c;
    } else if (b == '-') {
        return a - c;
    } else if (b == '*') {
        return a * c;
    } else
        return a / c;
    
    //return 0;
}
int main() {
    //	/*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    //	*/
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        scanf("%s", f + 1);
        for (int i = 0; i <= n; i++) dp[i][0][0] = dp[i][0][1] = k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                ll a1 = cal(dp[i - 1][j - 1][0], f[j], a[i]);
                ll a2 = cal(dp[i - 1][j - 1][1], f[j], a[i]);
                dp[i][j][0] = max(a1, a2);
                dp[i][j][1] = min(a1, a2);
                if (i > j) {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j][0]);
                    dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j][1]);
                }
            }
        }
        printf("%lld\n", dp[n][m][0]);
    }
}