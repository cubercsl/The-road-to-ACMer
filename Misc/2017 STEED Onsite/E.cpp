#include <bits/stdc++.h>
using namespace std;

char s[52];

bool isp(int st, int len)
{
    for (int i = 0; i <= len / 2; i++)
        if (s[st + i] != s[st + len - i - 1])
            return false;
    return true;
}

int main()
{
    while (cin >> s)
    {
        int len = strlen(s);
        int ans = 0;
        for (int i = len; i > 0; i--)
        {
            if (ans)
                break;
            for (int j = 0; j + i - 1 < len; j++)
                if (isp(j, i))
                {
                    ans = i;
                    break;
                }
        }
        cout << ans << endl;
    }
    return 0;
}
