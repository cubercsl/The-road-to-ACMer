#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, T;
    string ss;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> ss;
        vector<string> s(n);
        int pos = 0;
        int sgn = 1;
        if (n == 1)
        {
            cout << ss << endl;
            continue;
        }
        for (auto& t : ss)
        {
            // cout << pos << endl;
            s[pos].push_back(t);
            pos += sgn;
            if (pos == n)
                pos = n - 2, sgn = -1;
            else if (pos == -1)
                pos = 1, sgn = 1;
        }
        for (int i = 0; i < n; i++) cout << s[i];
        cout << endl;
    }
    return 0;
}
