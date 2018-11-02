#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x1, x2, y1, y2;
    while(~scanf("%d%d%d%d%d%d",&n, &m, &x1, &x2, &y1, &y2))
    {
        int ans = (y1 - x1 + 1) * ((x2 - 1) % 2 + (m - y2) % 2) + (n - y1 + x1 - 1) * (m % 2);
        ans = (ans + 1) / 2;
        printf("%d\n", ans);
    }
    return 0;
}