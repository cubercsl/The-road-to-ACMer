#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    while (gets(str))
    {
        int flag = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] > str[flag])
                flag = i;
        }
        for (int i = 0; i < strlen(str); i++)
        {
            printf("%c", str[i]);
            if (str[i] == str[flag])
                printf("(max)");
        }
        printf("\n");
    }
    return 0;
}
