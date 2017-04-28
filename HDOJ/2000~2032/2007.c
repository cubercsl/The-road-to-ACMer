#include <stdio.h>

int main()
{
    int m, n, temp;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if (m > n)
        {
            temp = m;
            m = n;
            n = temp;
        }
        int odd = 0, even = 0;
        for (int i = m; i <= n; i++)
        {
            if (i % 2)
                odd += i * i * i;
            else
                even += i * i;
        }
        printf("%d %d\n", even, odd);
    }
    return 0;
}
