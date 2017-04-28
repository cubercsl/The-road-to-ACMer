#include <stdio.h>

int main()
{
    int a[55] = {0, 1, 2, 3, 4};
    for (int i = 5; i < 55; i++)
        a[i] = a[i - 1] + a[i - 3];
    int n;
    scanf("%d", &n);
    while (n)
    {
        printf("%d\n", a[n]);
        scanf("%d", &n);
    }
    return 0;
}
