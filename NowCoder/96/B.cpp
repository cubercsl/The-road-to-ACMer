#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int ans = 0, t = 1;
        for (; a || b; a /= 10, b /= 10, t *= 10)
            ans += ((a % 10 + b % 10) % 10) * t;
        cout << ans << endl;
    }
}