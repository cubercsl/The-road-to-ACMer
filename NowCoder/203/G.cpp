#include <bits/stdc++.h>
using namespace std;

inline int sg(int x, int a, int b)
{
    if (x < a) return 0;
    if (a == 1) return (x - b - 1) % (a + b);
    int ret = (x - b) % (a + b) / a;
    if (ret == 0 || ret == 1) ret ^= 1;
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        vector<int> s(n);
        for (int i = 0; i < n; i++) scanf("%d", &s[i]);
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= a && s[i] <= b)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            puts("Yes");
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans ^= sg(s[i], a, b);
        puts(ans ? "Yes" : "No");
    }
}