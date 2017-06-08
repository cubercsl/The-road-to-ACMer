#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, p, q;
        long long a, b, mid, l = 0, r = 1e9, ans = -1;
        cin >> x >> y >> p >> q;
        while (l <= r)
        {
            mid = (l + r) / 2;
            a = mid * p - x, b = mid * q - y;
            if (a >= 0 && b >= 0 && a <= b)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (ans == -1)
            cout << -1 << endl;
        else
            cout << ans * q - y << endl;
    }
    return 0;
}