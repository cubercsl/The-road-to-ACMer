#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
int main()
{
    ll a, b, c, d, x = -1, y = -1;
    cin >> a >> b >> c >> d;
    for (ll i = 1; i < maxn; i++)
    {
        if (i * (i - 1) == 2 * a)
        {
            x = i;
        }
        if (i * (i - 1) == 2 * d)
        {
            y = i;
        }
        if (x != -1 && y != -1) break;
    }
    if (x == -1 || y == -1)
    {
        cout << "impossible" << endl;
        return 0;
    }
    if (x * y != b + c)
    {
        if (b + c == 0 && (a == 0 || d == 0))
        {
            int tmp = max(x, y);
            char c = x > y ? '0' : '1';
            for (int i = 0; i < tmp; i++) cout << c;
            cout << endl;
        }
        else
            cout << "impossible" << endl;

        return 0;
    }
    string ans = "";
    int l = 0, r = x;
    while (r > 0)
    {
        while (c >= r)
        {
            c -= r;
            b -= l;
            ans += "1";
        }
        ans += "0";
        r--;
        l++;
    }
    while (b >= l)
    {
        ans += "1";
        b -= l;
    }
    assert(c == 0 && b == 0);
    cout << ans << endl;
    return 0;
}