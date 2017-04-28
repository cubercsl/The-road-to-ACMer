#include <stdio.h>

int main()
{
    int m, n;
    int a[100][100];
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int imax = 0, jmax = 0, max = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
                max = abs(a[i][j]) > abs(max) ? imax = i, jmax = j, a[i][j] : max;
            }
        printf("%d %d %d\n", imax + 1, jmax + 1, max);
    }
    return 0;
}
