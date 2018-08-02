#include <bits/stdc++.h>
using namespace std;

const int N = 150;
int l;
int a[N];
int maze[N][N];
long long sum[N][N];
void baoli(int L)
{
    int p = 0;
    for (int i = 0; i <= 140; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            maze[k][i - k] = a[p];
            p = (p + 1) % L;
        }
    }
    for (int i = 1; i <= 2 * L; i++)
        for (int j = 1; j <= 2 * L; j++) sum[i][j] = maze[i - 1][j - 1];
    for (int i = 1; i <= 2 * L; i++)
        for (int j = 1; j <= 2 * L; j++) sum[i][j] += sum[i - 1][j];
    for (int i = 1; i <= 2 * L; i++)
        for (int j = 1; j <= 2 * L; j++) sum[i][j] += sum[i][j - 1];
}

inline long long solve(int x, int y)
{
    return 1LL * (x / l) * (y / l) * sum[l][l] + 1LL * (x / l) * sum[l][y % l] + 1LL * (y / l) * sum[x % l][l] + sum[x % l][y % l];
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int q;
        scanf("%d", &l);
        for (int i = 0; i < l; i++) scanf("%d", a + i);
        baoli(l);
        l <<= 1;
        scanf("%d", &q);
        while (q--)
        {
            static int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            ++x1, ++y1, ++x2, ++y2;
            long long ans = 0;
            ans += solve(x2, y2);
            ans -= solve(x1 - 1, y2);
            ans -= solve(x2, y1 - 1);
            ans += solve(x1 - 1, y1 - 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}