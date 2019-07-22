#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int a = 0, b = 0;
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            if (x & 1)
                a++;
            else
                b++;
        }
        if (a >= b)
            puts("2 1");
        else
            puts("2 0");
    }
}