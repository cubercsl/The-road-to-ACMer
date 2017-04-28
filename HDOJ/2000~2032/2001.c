#include <stdio.h>
#include <math.h>

int main()
{
    double x_1, y_1, x_2, y_2;
    double distance;
    while (scanf("%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2) != EOF)
    {
        distance = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
        printf("%.2f\n", distance);
    }
    return 0;
}
