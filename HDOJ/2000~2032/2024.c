#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char str[50];
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        gets(str);
        if (str[0] == '_' || (str[0] >= 'A' && str[0] <= 'z'))
        {
            int flag = 0;
            for (int i = 1; i < strlen(str); i++)
            {
                if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                printf("no\n");
            else
                printf("yes\n");
        }
        else
            printf("no\n");
    }
    return 0;
}
