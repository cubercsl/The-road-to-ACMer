//最少拦截系统, HDU1257 

/*Sample Input
8 389 207 155 300 299 170 158 65
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int n;
    while (cin >> n)
    {
        int a[100000];
        int dp[100000];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
