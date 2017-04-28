#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char str[102];
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
        gets(str);
        for (int i = 0; i < strlen(str); i++)
            switch (str[i])
            {
            case 'a':
                num1++;
                break;
            case 'e':
                num2++;
                break;
            case 'i':
                num3++;
                break;
            case 'o':
                num4++;
                break;
            case 'u':
                num5++;
                break;
            }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", num1, num2, num3, num4, num5);
        if (n)
            printf("\n");
    }
    return 0;
}
