#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct item
{
    double v, w;
} s[50];

bool cmp(item a, item b)
{
    return a.v / a.w > b.v / b.w;
}

int main()
{
    int n, c, kase = 0;
    while (cin >> n >> c)
    {
        for (int i = 0; i < n; i++)
            cin >> s[i].v;
        for (int i = 0; i < n; i++)
            cin >> s[i].w;
        sort(s, s + n, cmp);
        double now = 0, ans = 0;
        for (int i = 0;; i++)
        {
            if (now + s[i].w <= c)
                now += s[i].w, ans += s[i].v;
            else
            {
                ans += (c - now) / s[i].w * s[i].v;
                break;
            }
        }
        printf("Case %d: %.2f\n", ++kase, ans);
    }
    return 0;
}
