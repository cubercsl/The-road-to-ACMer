//Case Machine, POJ1276

/*Sample Input
735 3  4 125  6 5  3 350
633 4  500 30  6 100  1 5  0 1
735 0
0 3  10 100  10 50  10 10
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int C;
    int a[100020];
    int dp[100020];
    while (scanf("%d", &C) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        int N, t = 0;
        scanf("%d", &N);
        while (N--)
        {
            int D, n, k = 1;
            scanf("%d%d", &n, &D);
            while (n)
            {
                if (n >= k)
                    a[t++] = k * D, n -= k, k <<= 1;
                else
                {
                    a[t++] = n * D;
                    break;
                }
            }
        }
        for (int i = 0; i < t; i++)
            for (int j = C; j >= a[i]; j--)
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        printf("%d\n", dp[C]);
    }
    return 0;
}
