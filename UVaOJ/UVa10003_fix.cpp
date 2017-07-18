// Cutting Sticks, UVa10003

/*Sample Input
100
3
25 50 75
10
4
4 5 7 8
0
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

const int maxn = 55;
int l, n, c[maxn];
int dp[maxn][maxn];

void init()
{
    clr(dp, -1);
    for (int i = 0; i <= n; i++)
        dp[i][i + 1] = 0;
}

int dfs(int i, int j)
{
    if (dp[i][j] >= 0) return dp[i][j];
    int tmp = INF;
    for (int k = i + 1; k < j; k++)
        tmp = min(tmp, dfs(i, k) + dfs(k, j) + c[j] - c[i]);
    return dp[i][j] = tmp;
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
        init();
        cout << "The minimum cutting is " << dfs(0, n + 1) << "." << endl;
    }
    return 0;
}
