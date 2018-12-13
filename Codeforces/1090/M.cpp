#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int ans = 0, tmp = 0;
    a[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            tmp++;
        else
        {
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    ans = max(ans, tmp);
    printf("%d\n", ans);
}