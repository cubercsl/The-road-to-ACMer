#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, x, y, d;
        scanf("%d%d%d%d", &n, &x, &y, &d);
        int ans = INF;
        if (abs(y - x) % d == 0)
            ans = min(ans, abs(y - x) / d);
        else
        {
            if ((y - 1) % d == 0)
                ans = min(ans, (y - 1) / d + (x - 1 + d - 1) / d);
            if ((n - y) % d == 0)
                ans = min(ans, (n - y) / d + (n - x + d - 1) / d);
        }
        if (ans == INF) ans = -1;
        printf("%d\n", ans);
    }
}