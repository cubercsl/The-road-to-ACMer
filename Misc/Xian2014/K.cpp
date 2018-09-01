#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dfs(ll a, ll b)
{
    if (b == 0) return (a > 0) + 1;
    if (a < b) swap(a, b);
    return dfs(b, a % b) + (a - 1) / b;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        printf("Case #%d: ", ++kase);
        if (a == 0 && b == 0)
            puts("1");
        else if (a == 0 || b == 0)
            puts("2");
        else
            printf("%lld\n", dfs(a, b));
    }
}
