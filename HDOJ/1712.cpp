// ACboy needs your help, HDU1712

/*Sample Input
2 2
1 2
1 3
2 2
2 1
2 1
2 3
3 2 1
3 2 1
0 0
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
int dp[maxn];
int a[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m, n + m)
    {
        clr(dp, 0);
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = m; j > 0; j--)
                for (int k = 1; k <= m; k++)
                    if (j >= k)
                        dp[j] = max(dp[j], dp[j - k] + a[i][k]);
        cout << dp[m] << endl;
    }

    return 0;
}
