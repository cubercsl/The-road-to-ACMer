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

ll dp[5];
const int maxn = 1010;
ll C[maxn][maxn];
inline void init()
{
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
    }
    dp[0] = 1;
    dp[1] = 0, dp[2] = 1;
    for (int i = 3; i < 5; i++)
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();
    int n, k;
    while (cin >> n >> k)
    {
        ll ans = 0;
        for (int i = n - k; i <= n; i++)
            ans += C[n][i] * dp[n - i];
        cout << ans << endl;
    }
    return 0;
}
