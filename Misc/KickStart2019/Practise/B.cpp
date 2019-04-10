#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
char buf[N];

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", buf);
        int m = (n + 1) / 2;
        int ret = 0;
        for (int i = 0; i < m; i++) ret += buf[i] - '0';
        int ans = ret;
        for (int i = m; i < n; i++)
        {
            ret += buf[i] - '0';
            ret -= buf[i - m] - '0';
            ans = max(ans, ret);
        }
        printf("Case #%d: %d\n", t, ans);
    }
}