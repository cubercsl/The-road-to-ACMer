#include <stdio.h>

int main()
{
    int n;
    double num;
    scanf("%d", &n);
    while (n)
    {
        int positive = 0, negative = 0, zero = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &num);
            if (num > 0)
                positive++;
            else if (num < 0)
                negative++;
            else
                zero++;
        }
        printf("%d %d %d\n", negative, zero, positive);
        scanf("%d", &n);
    }
    return 0;
}
