#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 0;
        cin >> n;
        do
        {
            if (n & 1)
                ans <<= 1;;
        }
        while (n >>= 1);
        cout  << ans << endl;
    }
    return 0;
}
