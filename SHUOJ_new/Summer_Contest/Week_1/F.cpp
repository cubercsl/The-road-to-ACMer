#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[3];
    int t;
    while (cin >> t)
    {
        int cnt = 0;
        while (t--)
        {
            cin >> s;
            if (s[0] == 'X')
                cnt++;
            else
                cnt--;
        }
        cout << cnt << endl;
    }
    return 0;
}
