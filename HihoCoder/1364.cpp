#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int dp[N];
int cnt[12][12];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
        {
            static int w, p;
            cin >> w >> p;
            cnt[w][p]++;
        }
        for (int w = 1; w < 11; w++)
            for (int p = 1; p < 11; p++)
            {
                int num = cnt[w][p];
                for (int k = 1; num > 0; k <<= 1)
                {
                    int mul = min(k, num);
                    for (int j = m; j >= w * mul; j--)
                        dp[j] = max(dp[j], dp[j - w * mul] + p * mul);
                    num -= mul;
                }
            }
        cout << dp[m] << endl;
    }
    return 0;
}
