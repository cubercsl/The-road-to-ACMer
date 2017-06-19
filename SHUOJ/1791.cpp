#include <bits/stdc++.h>
using namespace std;

struct node
{
    int w, s;
    bool operator <(const node &b) const
    {
        return w < b.w;
    }
} ch[1002];

int main()
{
    int n;
    int pre = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ch[i].w >> ch[i].s;
    sort(ch , ch + n);
    int ans = -0x3f3f3f3f;
    for (int i = 1; i < n; i++)
        pre += ch[i - 1].w, ans = max(ans, pre - ch[i].s);
    cout << ans << endl;
    return 0;
}
