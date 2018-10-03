#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (auto& t : s)
    {
        if (t == '(')
            cnt++;
        else if (t == ')')
        {
            if (cnt == 0)
                ans++;
            else
                --cnt;
        }
    }
    ans = (ans + 1) / 2;
    cout << ans << endl;
    return 0;
}