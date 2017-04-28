#include <stdio.h>

int main()
{
    int n, a[100];
    scanf("%d", &n);
    while (n)
    {
        int flag = 0, temp;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int min = a[0];
        for (int i = 1; i < n; i++)
            min = a[i] < min ? flag = i, a[i] : min;
        temp = a[0];
        a[0] = a[flag];
        a[flag] = temp;
        for (int i = 0; i < n - 1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n - 1]);
        scanf("%d", &n);
    }
    return 0;
}
