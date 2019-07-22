#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int ans = 0;
        for (int i = 1; i < (1 << n) - 1; i++)
        {
            int a = 0, b = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                    a += (j + 1);
                else
                    b += (j + 1);
            }
            cerr << a << ' ' << b << endl;
            ans = max(ans, gcd(a, b));
        }
        cout << ans << endl;
    }
}