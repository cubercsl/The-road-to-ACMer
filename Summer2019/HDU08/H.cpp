#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
int a[N];
char b[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int L = -1, R = 1;
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++)
        {
            static char buf[5];
            scanf("%s", buf);
            b[i] = buf[0];
        }
        int sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (b[i] == 'L')
            {
                if (R >= a[i])
                    R += a[i];
            }
            if (b[i] == 'D')
            {
                if (-L >= a[i])
                    L -= a[i];
            }
            if (b[i] == 'N')
            {
                if (sum >= a[i])
                {
                    L -= a[i];
                    R += a[i];
                    sum += a[i];
                }
            }
        }
        if (L <= k && k <= R)
            puts("yes");
        else
            puts("no");
    }
}