// 不要62, HDU2089

/*Sample Input
1 100
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

int dp[10][10];

int solve(int t)
{
    int ans = 0;
    char s[10];
    sprintf(s, "%d", t);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < (s[i] - '0'); j++)

            if (j != 4 && !(i > 0 && s[i - 1] == '6' && j == 2))
                ans += dp[len - i][j];
        if (s[i] == '4')break;
        if (i > 0 && s[i] == '2' && s[i - 1] == '6')break;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    clr(dp, 0);
    dp[0][0] = 1;
    for (int i = 1; i <= 7; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                if (j != 4 && !(j == 6 && k == 2))
                    dp[i][j] += dp[i - 1][k];
    int a, b;
    while (cin >> a >> b, a + b)
    {
        int ans = solve(b + 1) - solve(a);
        cout << ans << endl;
    }
    return 0;
}
