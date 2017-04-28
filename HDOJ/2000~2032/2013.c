#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int sum = 1;
        for (int i = 1; i < n; i++)
            sum = (sum + 1) * 2;
        printf("%d\n", sum);
    }
    return 0;
}
