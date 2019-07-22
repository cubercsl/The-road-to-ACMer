#include <bits/stdc++.h>
using namespace std;

int solve(int m)
{
    return floor((log(2) / log(10) * m));
}

int main()
{
    int m;
    int kase = 0;
    while (~scanf("%d", &m))
    {
        printf("Case #%d: %d\n", ++kase, solve(m));
    }
}