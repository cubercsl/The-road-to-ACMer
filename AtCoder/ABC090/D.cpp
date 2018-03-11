#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    long long ans = 0;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j += i)
        {
            if (j + i - 1 <= n)
                ans += max(i - c, 0);
            else
                ans += max(n + 1 - j - c, 0);
        }
    if (c == 0) ans -= n;
    cout << ans << endl;
}