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
const int maxn = 205;
char maze[maxn][maxn];
int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n & 1) {
            printf("impossible\n");
            continue;
        }
        printf("possible\n");
        for (int i = 1; i <= n / 2; i++) {
            for (int k = 1; k <= n; k++) {
                maze[i][k] = -1;
                maze[i + n / 2][k] = 1;
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            for (int k = 1; k <= n - i; k++) maze[i][k] = 0;
        }
        for (int i = 1; i <= n / 2; i++) {
            for (int k = 1; k <= n / 2 - i + 1; k++) maze[i][n - k + 1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                if (k == 1)
                    printf("%d", maze[i][k]);
                else
                    printf(" %d", maze[i][k]);
            }
            puts("");
        }
    }
}