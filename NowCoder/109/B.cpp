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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> dp(n + 1);
    unordered_map<char, int> M;
    for (char c = 'a'; c <= 'z'; c++) M[c] = -1;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (p < m && s[i] == t[p])
        {
            p++;
            dp[i + 1] = dp[i] + 1;
            M[s[i]] = dp[i + 1];
        }
        else
        {
            if (~M[s[i]])
                dp[i + 1] = M[s[i]];
            else
                return cout << "No" << endl, 0;
        }
    }
    int mm = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] <= mm)
            mm = dp[i];
        else if (dp[i] == mm + 1)
            mm++;
    }
    if (mm == m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
