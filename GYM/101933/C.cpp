#include <bits/stdc++.h>
using namespace std;
int d[400], sum[400];
int main()
{
    int n,tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        d[tmp]++;
    }
    int cnt = 0, ans = 0;
    for (int i = 1; i <= 366; i++)
    {
        sum[i] = sum[i-1] + cnt;
        if (d[i]) cnt++;
        if (sum[i] +cnt >= 20)
        {
            cnt = 0;
            sum[i] = 0;
            ans++;
        }

    }
    if (sum[366]) ans++;
    printf("%d\n", ans);
}