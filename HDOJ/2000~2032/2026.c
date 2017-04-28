#include <stdio.h>
#include <string.h>

int main()
{
    char str[102];
    while (gets(str))
    {
        str[0] -= 'a' - 'A';
        for (int i = 0; i < strlen(str); i++)
            if (str[i] == ' ')
                str[i + 1] -= 'a' - 'A';
        printf("%s\n", str);
    }
    return 0;
}
