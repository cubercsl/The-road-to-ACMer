#include <bits/stdc++.h>
using namespace std;
int a[1 << 17];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int cur = -1;
        int t;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'S')
                cur = i;
            else if (s[i] == 'E')
                t = i;
            else if (s[i] == '@')
                cnt++;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (flag)
                break;
            for (int j = 0; j < a[i]; j++)
            {
                if (s[cur] == '@')
                {
                    s[cur] = '.';
                    cnt--;
                    int dis = 1e9;
                    int pos = -1;
                    if (!cnt)
                    {
                        cur++;
                        cnt++;
                        continue;
                    }
                    for (int k = t; k < s.length(); k++)
                    {
                        if (s[k] == '@')
                            if (dis >= k - t)
                            {
                                dis = k - t, pos = k;
                                break;
                            }
                    }
                    for (int k = t; k >= 0; k--)
                        if (s[k] == '@')
                            if (dis >= t - k)
                            {
                                dis = t - k, pos = k;
                                break;
                            }
                    if (pos != -1)
                    {
                        cur = pos;
                        s[pos] = '.';
                        cnt--;
                    }
                    else
                        cur++;
                }
                else
                    cur++;
                if (cur >= s.length())
                    break;
                if (!flag && s[cur] == 'E')
                {
                    if (i % 2)
                        cout << "Tabris" << endl;
                    else
                        cout << "mengxiang000" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
            cout << "None" << endl;
    }
}
