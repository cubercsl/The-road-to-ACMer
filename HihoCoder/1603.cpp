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
    string s;
    while (getline(cin, s))
    {
        bool flag = 0;
        int n = s.length();
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] == '@')
            {
                string ans;
                if (s[i + 1] == '@') continue;
                while ((s[++i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                    ans.pb(s[i]);
                if (ans.length())
                {
                    if (flag) cout << " ";
                    flag = 1;
                }
                cout << ans;
                i--;
            }
        }
    }
    return 0;
}
