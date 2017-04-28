#include <stdio.h>

int main()
{
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int n;
        scanf("%d",&n);
        double sum=0;
        for (int i=1;i<=n;i++)
        {
            int sgn=i%2?1:-1;
            sum+=sgn*1.0/i;
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
