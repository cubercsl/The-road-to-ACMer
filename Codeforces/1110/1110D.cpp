#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int cnt[N], dp[2][5][3];
template <class T>
inline T upmax(T& x, T y) { return x < y ? x = y : x; }
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x; i < n; i++) scanf("%d", &x), cnt[x]++;
    int ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 3; k++)
            {
                upmax(ans, upmax(dp[i & 1 ^ 1][k][0], dp[i & 1][j][k] + (cnt[i] - j) / 3));
                if (cnt[i] > j && cnt[i + 1] > k && cnt[i + 2] > 0)
                    upmax(ans, upmax(dp[i & 1 ^ 1][k + 1][1], dp[i & 1][j][k] + 1 + (cnt[i] - j - 1) / 3));
                if (cnt[i] > j + 1 && cnt[i + 1] > k + 1 && cnt[i + 2] > 1)
                    upmax(ans, upmax(dp[i & 1 ^ 1][k + 2][2], dp[i & 1][j][k] + 2 + (cnt[i] - j - 2) / 3));
                dp[i & 1][j][k] = 0;
            }
    printf("%d\n", ans);
}