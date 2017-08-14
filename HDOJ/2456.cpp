// 饭卡, HDU2456

/*Sample Input
1
50
5
10
1 2 3 2 1 1 2 3 2 1
50
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

const int maxn = 1005;
int dp[maxn];
int n, m, a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        if (m < 5)
        {
            cout << m << endl;
            continue;
        }
        sort(a, a + n);
        clr(dp, 0);
        for (int i = 0; i < n - 1; i++)
            for (int j = m - 5; j >= a[i]; j--)
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        cout << m - dp[m - 5] - a[n - 1] << endl;
    }
    return 0;
}
