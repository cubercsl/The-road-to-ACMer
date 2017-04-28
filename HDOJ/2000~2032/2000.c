#include <stdio.h>

int main()
{
    char ch[3];
    int temp;
    while (scanf("%s", ch) != EOF)
    {
        if (ch[0] > ch[1])
        {
            temp = ch[0];
            ch[0] = ch[1];
            ch[1] = temp;
        }
        if (ch[0] > ch[2])
        {
            temp = ch[0];
            ch[0] = ch[2];
            ch[2] = temp;
        }
        if (ch[1] > ch[2])
        {
            temp = ch[1];
            ch[1] = ch[2];
            ch[2] = temp;
        }
        printf("%c %c %c\n", ch[0], ch[1], ch[2]);
    }
    return 0;
}
