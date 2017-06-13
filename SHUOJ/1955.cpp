#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

ll t[100000];

int main()
{
    for (ll i = 0; i < 100000; i++)
    {
        t[i] = i * (i + 1) / 2 + 1;
        // cout << t[i] << endl;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = lower_bound(t, t + 100000, n) - t;
        // cout << ans << endl;
        if (t[ans] == n)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    return 0;
}
