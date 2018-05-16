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

const int N = 5005;

int dp[N][N], ans[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &dp[i][1]), ans[i][1] = dp[i][1];
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i + j - 1 <= n; i++)
        {
            dp[i][j] = dp[i][j - 1] ^ dp[i + 1][j - 1];
            ans[i][j] = max(dp[i][j], max(ans[i + 1][j - 1], ans[i][j - 1]));
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", ans[l][r - l + 1]);
    }
    return 0;
}
