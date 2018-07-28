#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> a;
    for (int i = 0, x; i < n; i++)
    {
        cout << 1 << endl;
        cin >> x;
        if (x == 0) return 0;
        a.push_back(x);
    }
    int l = 1, r = m;
    for (int i = 0, x;; (++i) %= n)
    {
        int mid = l + r >> 1;
        cout << mid << endl;
        cin >> x;
        if (x == 0) return 0;
        if (a[i] == -1)
        {
            if (x == -1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        else
        {
            if (x == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return 0;
}