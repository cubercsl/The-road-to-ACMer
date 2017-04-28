#include <stdio.h>

int isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 1;
    }
    return 0;
}

int main()
{
    int x, y, n;
    scanf("%d%d", &x, &y);
    while (x || y)
    {
        for (n = x; n <= y; n++)
            if (isPrime(n * n + n + 41))
                break;
        if (n == y + 1)
            printf("OK\n");
        else
            printf("Sorry\n");
        scanf("%d%d", &x, &y);
    }
    return 0;
}
