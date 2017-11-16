#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int cnt = 0;
    while (cin >> s)
    {
        int now = 0;
        for (auto t : s)
        {
            if (now == 0 || now == 4)
                now = t == 'd' || t == 'D' ? 1 : 0;
            else if (now == 1)
                now = t == 'o' || t == 'O' ? 2 : 0;
            else if (now == 2)
                now = t == 'g' || t == 'G' ? 3 : 0;
            else if (now == 3)
                now = t == 'e' || t == 'E' ? 4 : 0;
            if (now == 4) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}