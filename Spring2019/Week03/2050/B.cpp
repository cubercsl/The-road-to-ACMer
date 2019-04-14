#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int year, month, day, h, m, s;
        scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &h, &m, &s);
        int ans = (60 * m + s) % 100;
        if (year >= 2050)
            printf("%d\n", ans);
        else
            printf("%d\n", (3600 - ans) % 100);
    }
}
