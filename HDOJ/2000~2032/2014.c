#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int a[100], sum = 0;
        int max = -65536;
        int min = 65536;
        double avg;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for (int i = 0; i < n; i++)
        {
            max = a[i] > max ? a[i] : max;
            min = a[i] < min ? a[i] : min;
        }
        sum = sum - max - min;
        avg = sum * 1.0 / (n - 2);
        printf("%.2f\n", avg);
    }
    return 0;
}
