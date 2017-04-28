#include <stdio.h>
#include <math.h>

int main()
{
    double n;
    int m;
    while (scanf("%lf%d", &n, &m) != EOF)
    {
        double sum = 0.0;
        while (m--)
        {
            sum += n;
            n = sqrt(n);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}
