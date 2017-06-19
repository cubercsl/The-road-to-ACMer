#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        getchar();
        char s[20];
        int cnt;
        cin >> s;
        bool flag = 1;
        if (s[0] != '1')
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 1; i < strlen(s); i++)
        {
            if (s[i] != '1' && s[i] != '8')
            {
                flag = 0;
                break;
            }
            else if (s[i] == '1')
                cnt = 0;
            else if (s[i] == '8')
                cnt++;
            if (cnt > 2)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}
