#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int n;
    long long ans;
    int a[100010];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        if (a[0] == a[1] && a[1] == a[2])
        {
            ans = upper_bound(a, a + n, a[0]) - a;
            ans = ans * (ans - 1) * (ans - 2) / 6;
        }
        else if (a[0] != a[1] && a[1] == a[2])
        {
            ans = upper_bound(a, a + n, a[1]) - a - 1;
            ans = ans * (ans - 1) / 2;
        }
        else
            ans = upper_bound(a, a + n, a[2]) - a - 2;
        cout << ans << endl;
    }
    return 0;
}
