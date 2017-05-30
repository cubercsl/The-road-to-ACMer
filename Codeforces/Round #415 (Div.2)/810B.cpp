#include <bits/stdc++.h>
using namespace std;

struct node
{
    int k, l, x1, x2;
} s[100050];

int cmp(node a, node b)
{
    return a.x2 > b.x2;
}

int main()
{
    int n, f;
    while (cin >> n >> f)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].k >> s[i].l;
            s[i].x1 = min(s[i].l, s[i].k);
            s[i].x2 = min(s[i].l, s[i].k * 2) - s[i].x1;
        }
        sort(s, s + n, cmp);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < f)
                ans += min(s[i].l, s[i].k * 2);
            else
                ans += s[i].x1;
        }
        cout << ans << endl;
    }
    return 0;
}
