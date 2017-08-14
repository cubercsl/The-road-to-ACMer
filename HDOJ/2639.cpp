// Bone Collector II, HDU2639

/*Sample Input
3
5 10 2
1 2 3 4 5
5 4 3 2 1
5 10 12
1 2 3 4 5
5 4 3 2 1
5 10 16
1 2 3 4 5
5 4 3 2 1
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

const int maxn = 1005;
int dp[maxn][35];
int v[105], w[105], c[105];
int n, m, k;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        clr(dp, 0);
        for (int i = 0; i < n; i++)
            cin >> w[i];
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = m; j >= v[i]; j--)
            {
                int cnt = 0;
                for (int p = 0; p < k; p++)
                {
                    c[cnt++] = dp[j][p];
                    c[cnt++] = dp[j - v[i]][p] + w[i];
                }
                sort(c, c + cnt, cmp);
                cnt = unique(c, c + cnt) - c;
                for (int p = 0; p < k && p < cnt; p++)
                    dp[j][p] = c[p];
            }
        }
        cout << dp[m][k - 1] << endl;
    }
    return 0;
}
