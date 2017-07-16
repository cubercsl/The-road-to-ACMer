#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 55;
int l, n, c[maxn];
int dp[maxn][maxn];

void solve()
{
    clr(dp, 0x3f);
    for (int i = 0; i <= n; i++)
        dp[i][i + 1] = 0;
    for (int i = 2; i <= n + 1; i++)
        for (int j = 0; j + i <= n + 1; j++)
            for (int k = j + 1; k < j + i; k++)
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][j + i] + c[j + i] - c[j]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> l, l)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        c[n + 1] = l;
        solve();
        cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
    }
    return 0;
}
