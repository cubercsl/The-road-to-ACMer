#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[102];
    while (cin >> a)
    {
        bool flag = 0;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == '(')
                cnt++;
            ans = max(cnt, ans);
            if (a[i] == ')')
                cnt--;
            if (cnt < 0)
            {
                flag = 1;
                break;
            }
        }
        if (cnt == 0 && !flag)
            cout << "YES " << ans << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
