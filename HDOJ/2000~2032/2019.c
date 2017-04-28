#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (n || m)
    {
        int a[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n - 1; i++)
            if (a[i] < m && a[i + 1] >= m)
                printf("%d %d ", a[i], m);
            else
                printf("%d ", a[i]);
        printf("%d\n", a[n - 1]);
        scanf("%d%d", &n, &m);
    }
    return 0;
}
