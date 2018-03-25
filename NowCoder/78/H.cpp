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
    long double a, b, c;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        long double d = a * c / b;
        string s = to_string(d);
        string ans;
        int n = s.length();
        int i = 0;
        while (i < n && s[i] != '.') i++;
        i += 3;
        if (s[i] < '5')
            ans = s.substr(0, i);
        else if (s[i] > '5')
        {
            d += 0.01;
            ans = to_string(d).substr(0, i);
        }
        else if (s[i] == '5')
        {
            bool flag = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] != '0')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag || (s[i - 1] & 1))
            {
                d += 0.01;
                ans = to_string(d).substr(0, i);
            }
            else
                ans = s.substr(0, i);
        }
        cout << ans << endl;
    }
    return 0;
}