#include <stdio.h>

int main()
{
    int score;
    while (scanf("%d", &score) != EOF)
    {
        if (score > 100 || score < 0)
            printf("Score is error!\n");
        else if (score >= 90)
            printf("A\n");
        else if (score >= 80)
            printf("B\n");
        else if (score >= 70)
            printf("C\n");
        else if (score >= 60)
            printf("D\n");
        else if (score >= 0)
            printf("E\n");
    }
    return 0;
}
