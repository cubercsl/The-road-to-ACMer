#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = n;; i++)
        {
            if ((i % 7 == 0) && (i % 4 != 0))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}
