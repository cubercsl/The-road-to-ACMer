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
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ch[i].w >> ch[i].s;
    sort(ch, ch + n);
    int pre = 0, ans = -0x3f3f3f3f;
    for (int i = 0; i < n - 1; i++)
    {
        pre += ch[i].w;
        ans = max(ans, pre - ch[i + 1].s);
    }
    cout << ans << endl;
    return 0;
}
