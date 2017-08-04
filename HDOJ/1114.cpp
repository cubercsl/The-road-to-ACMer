// Piggy-Bank, HDU1114

/*Sample Input
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
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

const int maxn = 10005;
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int T;
    cin >> T;
    while (T--)
    {
        clr(dp, 0x3f);
        dp[0] = 0;
        int E, F, n;
        cin >> E >> F >> n;
        while (n--)
        {
            int P, W;
            cin >> P >> W;
            for (int i = W ; i <= F - E; i++)
                dp[i] = min(dp[i], dp[i - W] + P);
        }
        int ans = dp[F - E];
        if (ans < INF)
            cout << "The minimum amount of money in the piggy-bank is " << ans << "." << endl;
        else
            cout << "This is impossible." << endl;
    }
    return 0;
}
