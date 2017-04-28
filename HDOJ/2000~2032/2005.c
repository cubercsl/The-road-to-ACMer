#include <stdio.h>

int leep(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    else if (year % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int year, month, day;
    while (scanf("%d/%d/%d", &year, &month, &day) != EOF)
    {
        switch (month)
        {
        case 12:
            day += 30;
        case 11:
            day += 31;
        case 10:
            day += 30;
        case 9:
            day += 31;
        case 8:
            day += 31;
        case 7:
            day += 30;
        case 6:
            day += 31;
        case 5:
            day += 30;
        case 4:
            day += 31;
        case 3:
            day += 28 + leep(year);
        case 2:
            day += 31;
        }
        printf("%d\n", day);
    }
    return 0;
}
