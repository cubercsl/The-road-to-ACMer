#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n % 2 == 1 && m % 2 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++) putchar('(');
                puts("");
            }
        }
        else if ((n % 2 == 1 && m % 2 == 0))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j += 2) printf("()");
                puts("");
            }
        }
        else if ((n % 2 == 0 && m % 2 == 1))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i & 1)
                        putchar(')');
                    else
                        putchar('(');
                }
                puts("");
            }
        }
        else if (n % 2 == 0 && m % 2 == 0)
        {
            if (n == 4 && m >= 4)
            {
                for (int i = 0; i < m; i++) putchar('(');
                puts("");
                for (int i = 0; i < m / 2; i++) putchar('(');
                for (int i = 0; i < m / 2; i++) putchar(')');
                puts("");
                for (int i = 0; i < m / 2; i++) putchar(')');
                for (int i = 0; i < m / 2; i++) putchar('(');
                puts("");
                for (int i = 0; i < m; i++) putchar(')');
                puts("");
                continue;
            }
            if (m == 4 && n >= 4)
            {
                for (int i = 0; i < n / 2; i++)
                {
                    for (int j = 0; j < m / 2; j++) putchar('(');
                    for (int j = 0; j < m / 2; j++) putchar(')');
                    puts("");
                }
                for (int i = 0; i < n / 2; i++)
                {
                    for (int j = 0; j < m; j += 2) printf("()");
                    puts("");
                }
                continue;
            }
            if (n < 6 || m < 6)
            {
                if (n >= m)
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j += 2) printf("()");
                        puts("");
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            if (i & 1)
                                putchar(')');
                            else
                                putchar('(');
                        }
                        puts("");
                    }
                }
            }
            else
            {
                for (int i = 0; i < m; i++) putchar('(');
                puts("");
                for (int i = 1; i < n - 1; i++)
                {
                    if (i & 1)
                    {
                        putchar('(');
                        for (int i = 1; i < m - 1; i += 2) printf("()");
                        putchar(')');
                    }
                    else
                    {
                        for (int i = 0; i < m; i += 2) printf("()");
                    }
                    puts("");
                }
                for (int i = 0; i < m; i++) putchar(')');
                puts("");
            }
        }
    }
}