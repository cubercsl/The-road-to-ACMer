#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int x1, x2, y1, y2, x, y;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x >> y)
    {
        if (abs(x2 - x1) % x || abs(y2 - y1) % y)
            cout << "NO" << endl;
        else if ((abs(x2 - x1) / x) % 2 == (abs(y2 - y1) / y) % 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
