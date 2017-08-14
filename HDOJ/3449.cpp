// Consumer, HDU3449

/*Sample Input
3 800
300 2 30 50 25 80
600 1 50 130
400 3 40 70 30 40 35 60
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

const int maxn = 1e5 + 5;
int n, w, p, m, c, v;
int dp[maxn], tp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> w)
    {
        clr(dp, 0);
        while (n--)
        {
            cin >> p >> m;
            memcpy(tp, dp, sizeof(dp));
            while (m--)
            {   // 组内进行01背包
                cin >> c >> v;
                for (int i = w - p; i >= c; i--)
                    tp[i] = max(tp[i], tp[i - c] + v);
            }
            for (int i = p; i <= w; i++)
                dp[i] = max(dp[i], tp[i - p]);
        }
        cout << dp[w] << endl;
    }
    return 0;
}
