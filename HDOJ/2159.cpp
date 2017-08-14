// FATE, HDU2159

/*Sample Input
10 10 1 10
1 1
10 10 1 9
1 1
9 10 2 10
1 1
2 2
*/

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

const int maxn = 105;
int dp[maxn][maxn]; // 消耗，杀怪
int a, b, n, m, k, s;

int solve()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= s; j++)
            if (dp[i][j] >= n)
                return m - i;
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> m >> k >> s)
    {
        clr(dp, 0);
        while (k--)
        {
            cin >> a >> b;
            for (int i = b; i <= m; i++)
                for (int j = 1; j <= s && i >= b * j; j++)
                    dp[i][j] = max(dp[i][j], dp[i - b][j - 1] + a);
        }
        cout << solve() << endl;
    }
    return 0;
}
