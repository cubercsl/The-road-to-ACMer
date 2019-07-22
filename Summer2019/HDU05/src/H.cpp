#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
long long dp[N];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= m; i++) scanf("%lld", &dp[i]);
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            for (int j = 1; j <= m; j++)
            {
                if (dp[j] != 0)
                {
                    x = j;
                    printf("%d ", x);
                    break;
                }
            }
            assert(x);
            for (int j = x; j <= m; j++)
                dp[j] -= dp[j - x];
        }
        puts("");
    }
}