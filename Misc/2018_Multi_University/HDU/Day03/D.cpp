#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int k;
        scanf("%d", &k);
        if (k == 1)
            puts("5");
        else if (k == 2)
            puts("7");
        else
            printf("%d\n", k + 5);
    }
}