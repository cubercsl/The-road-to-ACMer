#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, m, c;
    while (cin >> n >> t >> m >> c)
    {
        int no = ceil(1.0 * n / m) * t;
        int yes = 0;
        int cnt = 0;
        while (cnt < n)
        {
            yes += t;
            cnt += m;
            if (yes > c)
                cnt += k;
        }
        if (yes < no)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
