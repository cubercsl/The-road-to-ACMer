#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
int a[N][N], b[N][N];
char s[N][N];
int x[N >> 2];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
    {
        memset(x, 0, sizeof(x));
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = min(a[i][j - 1] + 1, j - x[s[i][j]]);
            x[s[i][j]] = j;
        }
    }
    for (int j = 1; j <= m; j++)
    {
        memset(x, 0, sizeof(x));
        for (int i = 1; i <= n; i++)
        {
            b[i][j] = min(b[i - 1][j] + 1, i - x[s[i][j]]);
            x[s[i][j]] = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            memset(x, 0, sizeof(x));
            for (int k = 0; k < a[i][j]; k++) x[k] = b[i][j - k];
            for (int k = 1; k < a[i][j]; k++) x[k] = min(x[k], x[k - 1]);
            int t = a[i][j];
            for (int k = 0; k < b[i][j]; k++)
            {
                t = min(t, a[i - k][j]);
                while (x[t - 1] < k + 1) --t;
                ans += t;
            }
        }
    printf("%lld\n", ans);
}