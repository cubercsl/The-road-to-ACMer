#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int dp[502];
    int v[52], w[52];
    int kase = 0;
    int n, c;
    while (cin >> n >> c)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            cin >> w[i];
        for (int i = 0; i < n; i++)
            for (int j = c; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        cout << "Case " << ++kase << ":" << dp[c] << endl;
    }
    return 0;
}
