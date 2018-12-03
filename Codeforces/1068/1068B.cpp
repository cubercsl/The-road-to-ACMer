#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll b;
    cin >> b;
    ll ans = 0;
    for (ll i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            if (i == b / i)
                ans++;
            else
                ans += 2;
        }
    }
    cout << ans << endl;
}