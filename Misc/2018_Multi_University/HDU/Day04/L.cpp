#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int w[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
        int ans = sqrt(abs(w[1] - w[n]));
        for (int i = 1; i <= n; i++)
        {
            int a = sqrt(abs(w[1] - w[i]));
            int b = sqrt(abs(w[n] - w[i]));
            ans = min(ans, a + b);
        }
        printf("%d\n", ans);
    }
}