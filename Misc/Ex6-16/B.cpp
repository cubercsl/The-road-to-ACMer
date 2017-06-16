#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int n,q;
    int a[50010];
    scanf("%d%d",&n,&q);
    a[0]=INF;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        while(q--)
        {
            int h;
            scanf("%d",&h);
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(a[i]<=h&&a[i-1]>h)
                    cnt++;
            printf("%d\n",cnt+1);
        } 
	return 0;
}

