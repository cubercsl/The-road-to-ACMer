#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        int d;
        cin >> d;
        string s;
        cin >> s;
        int n = s.length();
        cout << "Case #" << ++kase << ": ";
        int sum = 0, cur = 1;
        for (auto& t : s) sum += t == 'S';
        if (sum > d)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            vector<int> v(n);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'S')
                    v[i] = cur;
                else
                    cur <<= 1;
            }
            sum = accumulate(v.begin(), v.end(), 0);
            // cerr << sum << endl;
            if (sum <= d)
                cout << 0 << endl;
            else
            {
                int ans = 0;
                for (int i = n - 2; ~i && sum > d; i--)
                {
                    int j = i;
                    for (int j = i; j < n - 1 && v[j] == 0 && v[j + 1] != 0 && sum > d; j++)
                    {
                        sum -= v[j + 1];
                        v[j + 1] >>= 1;
                        sum += v[j + 1];
                        swap(v[j], v[j + 1]);
                        // cerr << j << " " << j + 1 << endl;
                        ans++;
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}