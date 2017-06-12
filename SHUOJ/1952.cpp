#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
long long odd[100010], even[100010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        memset(odd, 0, sizeof(odd));
        memset(even, 0, sizeof(even));
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
        {
            int num;
            scanf("%d", &num);
            if (num % 2)
                even[i] = even[i - 1] + 1, odd[i] = odd[i - 1];
            else
                odd[i] = odd[i - 1] + 1, even[i] = even[i - 1];
        }
        while (q--)
        {
            int a, b;
            long long ans;
            scanf("%d%d", &a, &b);
            ans = (odd[b] - odd[a - 1]) * (even[b] - even[a - 1]);
            printf("%lld\n", ans);
        }
    }

    return 0;
}
