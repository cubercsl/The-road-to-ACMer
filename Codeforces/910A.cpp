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

int dp[105];
char s[105];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, d;
    while (~scanf("%d%d", &n, &d))
    {
        clr(dp, 0x3f);
        dp[0] = 0;
        scanf("%s", s);
        for (int i = 0; i < n; i++)
            if (s[i] != '0')
                for (int j = (max(i - d, 0)); j < i; j++)
                    dp[i] = min(dp[j] + 1, dp[i]);
        printf("%d\n", dp[n - 1] != INF ? dp[n - 1] : -1);
    }
    return 0;
}
