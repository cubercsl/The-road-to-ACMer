#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: ", ++kase);
        puts((int)sqrt(n + 0.1) & 1 ? "odd" : "even");
     }
}