// Coins, POJ1742

/*Sample Input
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
*/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, cnt;
int a[102], c[102];
int b[1000002];
bool dp[100002];

int main()
{
    while (cin >> n >> m, m && n)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        int id = 0;
        for (int i = 0; i < n; i++)
        {
            int k = 1;
            while (c[i] > k)
            {
                b[id++] = k * a[i];
                c[i] -= k;
                k <<= 1;
            }
            b[id++] = c[i] * a[i];
        }
        // for (int i = 0; i < id; i++)
        //      cout << b[i] << endl;
        dp[0] = 1, cnt = 0;
        for (int i = 0; i < id; i++)
            for (int j = m; j >= b[i]; j--)
                dp[j] = dp[j - b[i]];
        for (int i = 1; i <= m; i++)
            if (dp[i])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
