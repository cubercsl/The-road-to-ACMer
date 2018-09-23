#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ca, ba, pa;
    int cr, br, pr;
    while(~scanf("%d%d%d",&ca,&ba,&pa))
    {
        scanf("%d%d%d", &cr, &br, &pr);
        int ans = max(cr - ca, 0) + max(br - ba, 0) + max(pr - pa, 0);
        printf("%d\n", ans);
    }
    return 0;
}