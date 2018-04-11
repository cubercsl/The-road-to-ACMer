#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                a.push_back(v[i]);
            else
                b.push_back(v[i]);
        }
        sort(v.begin(), v.end());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = -1;
        for (int i = 0; i < n && ans == -1; i++)
        {
            if (i & 1)
            {
                if (a[i >> 1] != v[i]) ans = i;
            }
            else
            {
                if (b[i >> 1] != v[i]) ans = i;
            }
        }
        cout << "Case #" << ++kase << ": ";
        if (~ans)
            cout << ans << endl;
        else
            cout << "OK" << endl;
    }
    return 0;
}