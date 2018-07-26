#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> r, c;
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = n << 1;
    for (int i = 0, x, y; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        if (!r[x]) r[x] = 1, --ans;
        if (!c[y]) c[y] = 1, --ans;
    }
    if (n & 1 && !r[n / 2 + 1] && !c[n / 2 + 1]) --ans;
    printf("%d\n", ans);
}