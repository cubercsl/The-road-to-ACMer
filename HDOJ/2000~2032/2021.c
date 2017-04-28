#include <stdio.h>

int main()
{
    int n, salary;
    int money[6] = {100, 50, 10, 5, 2, 1};
    scanf("%d", &n);
    while (n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &salary);
            for (int j = 0; j < 6; j++)
            {
                count += salary / money[j];
                salary %= money[j];
            }
        }
        printf("%d\n", count);
        scanf("%d", &n);
    }
    return 0;
}
