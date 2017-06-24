#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            int num;
            scanf("%d",&num);
            a[i]=a[i-1]+num;
        }
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",a[r]-a[l-1]);
        }
    }
    return 0;
}
