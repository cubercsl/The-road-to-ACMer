#include <stdio.h>

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int cnt = 0;
        for (int i = m; i <= n; i++)
        {
            int a = i % 10;
            int b = i / 10 % 10;
            int c = i / 100;
            if (a * a * a + b * b * b + c * c * c == i)
            {
                if (cnt)
                {
                    printf(" %d", i);
                    cnt++;
                }
                else
                {
                    printf("%d", i);
                    cnt++;
                }
            }
        }
        if (cnt)
            printf("\n");
        else
            printf("no\n");
    }
    return 0;
}
