#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        set<pair<int, int>> s;
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                if (a % i == 0 && b % j == 0)
                {
                    int x = i, y = j;
                    if (x > y) swap(x, y);
                    s.insert({x, y});
                }
        printf("%d\n", (int)s.size());
    }
    return 0;
}