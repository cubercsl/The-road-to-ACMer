#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[26], b[26];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (auto c : s) a[c - 'A']++;
        for (auto c : t) b[c - 'A']++;
        ll ans = 0;
        for (int i = 0; i < 26; i++)
            ans += (ll)a[i] * (ll)b[i];
        ans *= n;
        cout << ans << endl;
    }
    return 0;
}
