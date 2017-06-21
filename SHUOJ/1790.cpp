#include <bits/stdc++.h>
using namespace std;

struct node
{
    int w, s;
    bool operator < (const node &b) const
    {
        return w - b.s < b.w - s;
    }
} ch[1002];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> ch[i].w >> ch[i].s;
        sort(ch, ch + n);
        long long pre = 0, ans = -0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, pre - ch[i].s);
            pre += ch[i].w;
        }
        cout << ans << endl;
    }
    return 0;
}
