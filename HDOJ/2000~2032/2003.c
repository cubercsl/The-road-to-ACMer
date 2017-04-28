#include <stdio.h>

int main()
{
    double num;
    while (scanf("%lf", &num) != EOF)
        printf("%.2f\n", num > 0 ? num : -num);
    return 0;
}
