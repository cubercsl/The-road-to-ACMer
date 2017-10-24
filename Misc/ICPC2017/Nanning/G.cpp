#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    int l;
    double r[15];
    while(scanf("%d",&l)==1)
    {
        if(l==-1) break;
        scanf("%lf",&r[0]);
        for(int i=1;i<=12;i++)
        {
            double temp=sqrt(r[0]*r[0]*r[i-1]*(r[0]*2+r[i-1]));
            r[i]=r[0]*r[0]*r[i-1]/(r[0]*r[0]+2*r[0]*r[i-1]+2*temp);
        }
        int k;
        while(l--)
        {
            scanf("%d",&k);
            printf("%d %d\n",k,(int)r[k]);
        }
    }
    return 0;
}
