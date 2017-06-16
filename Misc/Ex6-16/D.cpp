#include <iostream>
#include <cstring>
using namespace std;

int dp[100010];
int a[100010];
int l, s, t, n;
const int INF = 0x3f3f3f3f;
int main()
{
    while (cin >> l >> s >> t >> n)
    {
        memset(dp, 0x3f, sizeof(dp));
        memset(a, 0, sizeof(a));
        while (n--)
        {
            int x;
            cin >> x;
            a[x] = 1;
        }
        dp[0] = 0;
        for (int i = 0 ; i <= l ; i++)
        {
            for (int j = i + s ; j <= i + t; j++)
            {
                if (j >= l)
                    dp[l] = min(dp[l], dp[i]);
                else
                    dp[j] = min(dp[i] + a[j], dp[j]);
            }
        }
        cout << dp[l] << endl;
    }
    return 0;
}
