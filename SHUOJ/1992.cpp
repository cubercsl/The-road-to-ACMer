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

const int maxn = 505;
int n, m;
int dp[maxn][maxn];
int s[maxn];

int dfs(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 1) return dp[i][j] = s[j];
    int tmp, ret = INF;
    for (int k = 1; k <= j; k++)
    {
        tmp = max(dfs(i - 1, k), s[j] - s[k]);
        ret = min(ret, tmp);
    }
    return dp[i][j] = ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    while (cin >> n >> m)
    {
        clr(dp, -1);
        int num;
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            s[i] = s[i - 1] + num;
        }
        cout << "Case " << ++kase << ": " << dfs(m, n) << endl;
    }
    return 0;
}
