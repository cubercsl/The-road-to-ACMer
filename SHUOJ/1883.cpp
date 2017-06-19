#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, m;
int a[maxn];


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    return 0;
}
