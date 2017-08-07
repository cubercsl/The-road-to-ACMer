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
const int maxm = 1005;
int dp[maxn][maxm];
int pre[maxn][maxm];
int cost[maxn], val[maxn];
int b, n, totscore, totcost;
vector <int> ans;

void solve()
{
    clr(dp, 0);
    clr(pre, -1);
    for (int i = 1; i <= n; i++)
        for (int k = b; k >= 0; k--)
        {
            if (k < cost[i])
                dp[i][k] = dp[i - 1][k], pre[i][k] = pre[i - 1][k];
            else if (dp[i - 1][k] < dp[i - 1][k - cost[i]] + val[i])
                dp[i][k] = dp[i - 1][k - cost[i]] + val[i], pre[i][k] = i;
            else
                dp[i][k] = dp[i - 1][k], pre[i][k] = pre[i - 1][k];
        }
    totscore = dp[n][b];
    int now = b, pos = n;
    while (pre[pos][now] != -1)
    {
        int tmp = pre[pos][now];
        totcost += cost[tmp];
        ans.pb(tmp);
        pos = tmp - 1, now -= cost[tmp];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        cin >> b >> n;
        for (int i = 1; i <= n; i++)
            cin >> val[i] >> cost[i];
        totcost = 0, totscore = 0;
        ans.clear();
        solve();
        cout << "Case #" << ++kase << ":" << endl;
        cout << totscore << " " << totcost << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (i)cout << ans[i] << " ";
            else cout << ans[i] << endl;
        }
    }
    return 0;
}
