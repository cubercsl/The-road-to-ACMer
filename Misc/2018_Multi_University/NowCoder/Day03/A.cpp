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
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 37;
int dp[maxn][maxn][maxn][maxn][2];
ll num[maxn][maxn][maxn][maxn][2];
struct P {
    int p, a, c, m, g;
};
P foo[maxn];
 
int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d%d", &foo[i].p, &foo[i].a, &foo[i].c, &foo[i].m,
                  &foo[i].g);
        }
        // /*
        int P, A, C, M;
        scanf("%d%d%d%d", &P, &A, &C, &M);
        for (int p = 0; p <= P; p++) {
            for (int a = 0; a <= A; a++) {
                for (int c = 0; c <= C; c++) {
                    for (int m = 0; m <= M; m++) {
                        for (int i = 1, u, v, temp; i <= n; i++) {
                            u = i & 1;
                            v = u ^ 1;
                            dp[p][a][c][m][u] = dp[p][a][c][m][v];
                            num[p][a][c][m][u] = num[p][a][c][m][v];
                            if (p < foo[i].p || a < foo[i].a || c < foo[i].c ||
                                m < foo[i].m)
                                continue;
                            temp = dp[p - foo[i].p][a - foo[i].a][c - foo[i].c]
                                     [m - foo[i].m][v] +
                                   foo[i].g;
                            if (temp > dp[p][a][c][m][u]) {
                                dp[p][a][c][m][u] = temp;
                                num[p][a][c][m][u] =
                                    num[p - foo[i].p][a - foo[i].a]
                                       [c - foo[i].c][m - foo[i].m][v];
                                num[p][a][c][m][u] |= (1LL << i);
                            }
                        }
                    }
                }
            }
        }
        vector<int> ans;
 
        int u = n & 1;
        ll val = num[P][A][C][M][u];
        for (int i = 1; i <= n; i++) {
            if (val & (1LL << i)) {
                ans.pb(i);
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) {
            if (!i)
                printf("%d", ans[i] - 1);
            else
                printf(" %d", ans[i] - 1);
        }
        puts("");
        // */
    }
}