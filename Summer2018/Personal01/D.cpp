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
char a[N];
int dp[N][26];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        clr(dp, 0);
        int n, q;
        scanf("%d%d", &n, &q);
        scanf("%s", a);
        dp[1][a[0] - 'a']++;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 26; j++)
                dp[i][j] = dp[i - 1][j];
            dp[i][a[i - 1] - 'a']++;
        }
        while (q--)
        {
            static int l, r;
            static char b;
            scanf("%d %d %c", &l, &r, &b);
            int ans1, ans2;
            ans1 = dp[n][b - 'a'] * ((l - 1) / n) + dp[(l - 1) % n][b - 'a'];
            ans2 = dp[n][b - 'a'] * (r / n) + dp[r % n][b - 'a'];
            printf("%d\n", ans2 - ans1);
        }
    }
    return 0;
}