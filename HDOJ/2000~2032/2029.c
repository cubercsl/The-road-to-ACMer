#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int flag = 1;
        scanf("%s", str);
        for (int i = 0; i < strlen(str) / 2; i++)
            if (str[i] != str[strlen(str) - 1 - i])
            {
                flag = 0;
                break;
            }
        if (flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
