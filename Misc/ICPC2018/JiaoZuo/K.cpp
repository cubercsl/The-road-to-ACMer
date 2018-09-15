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
const int mod = 1e9 + 7;
ll dp[605][10005];

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
        int n, Q;
        scanf("%d%d", &n, &Q);
        vector<int> cost;
        for (int i = 1, v, c; i <= n; i++) {
            scanf("%d%d", &v, &c);
            for (int k = 0; k < c; k++) {
                cost.pb(v * (1 << k));
            }
        }
        clr(dp[0], 0);
        dp[0][0] = 1;
        int sz = cost.size();
        for (int i = 1; i <= sz; i++) {
            for (int s = 0; s <= 10000; s++) {
                dp[i][s] = dp[i - 1][s];
                if (s >= cost[i - 1]) dp[i][s] += dp[i - 1][s - cost[i - 1]];
                dp[i][s] %= mod;
            }
        }
        for (int i = 0, s; i < Q; i++) {
            scanf("%d", &s);
            printf("%lld\n", dp[sz][s]);
        }
    }
}