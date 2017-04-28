#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char a[1000];
        int count = 0;
        scanf("%s", a);
        for (int i = 0; i < strlen(a); i++)
            if (a[i] >= '0' && a[i] <= '9')
                count++;
        printf("%d\n", count);
    }
    return 0;
}
