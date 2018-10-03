#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int s[N], ans[N], a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        while (top && a[s[top - 1]] < a[i]) ans[s[--top]] = i;
        s[top++] = i;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}