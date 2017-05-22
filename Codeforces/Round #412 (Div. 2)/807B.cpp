#include <bits/stdc++.h>
using namespace std;

int p;
bool judge(int s)
{
    int i = (s / 50) % 475;
    for (int j = 0; j < 25; j++)
    {
        i = (i * 96 + 42) % 475;
        if (i + 26 == p)
            return true;
    }
    return false;
}

int main()
{
    int x, y;
    while (cin >> p >> x >> y)
    {
        int cnt = 0;
        int t = x;
        bool flag = 0;
        while (t - 50 >= y)
        {
            t -= 50;
            if (judge(t))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << cnt << endl;
        else
        {
            while (!judge(x))
            {
                cnt++;
                x += 50;
                if (judge(x))
                    break;
                x += 50;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
