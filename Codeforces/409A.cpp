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
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    string s;
    int a[105];
    while (cin >> s)
    {
        clr(a, 0);
        int k = s.length();
        int ans = 0;
        for (int i = 0; i < k - 1; i++)
        {
            if (s[i] == 'V' && s[i + 1] == 'K')
            {
                a[i] = a[i + 1] = 1;
                ans++;
                i++;
            }
        }
        for (int i = 0; i < k - 1; i++)
        {
            if ((s[i] == 'V' || s[i + 1] == 'K') && a[i] == 0 && a[i + 1] == 0)
            {
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
