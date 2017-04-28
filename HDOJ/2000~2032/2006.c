#include <stdio.h>

int main()
{
    int n, num;
    while (scanf("%d", &n) != EOF)
    {
        int sum = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if (num % 2)
                sum *= num;
        }
        printf("%d\n", sum);
    }
    return 0;
}
