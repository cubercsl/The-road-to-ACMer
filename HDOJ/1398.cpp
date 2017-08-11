// Square Coins, HDU1398

/*Sample Input
2
10
30
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

const int maxn = 305;
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    dp[0] = 1;
    for (int i = 1; i <= 17; i++)
        for (int j = i * i; j <= maxn; j++)
            dp[j] += dp[j - i * i];
    while (cin >> n, n)
        cout << dp[n] << endl;
    return 0;
}
