#include <bits/stdc++.h>
using namespace std;

struct node
{
    double b;
    double e;
} tmp[100];

int main()
{
    int n, m, i, j;
    double x, y, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%lf%lf", &tmp[i].b, &tmp[i].e);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%lf%lf", &x, &y);
        for (j = 0; j < n; j++)
        {
            if (x > tmp[j].b && y < tmp[j].e)
                sum += y - x;
            else if (x < tmp[j].b && y > tmp[j].e)
                sum += tmp[j].e-tmp[j].b;
            else if (x > tmp[j].b && x < tmp[j].e && y > tmp[j].e)
                sum += tmp[j].e-x;
            else if (y > tmp[j].b && y < tmp[j].e && x < tmp[j].b)
                sum += y - tmp[j].b;
        }
    }
    printf("%.3lf\n", sum);
}
