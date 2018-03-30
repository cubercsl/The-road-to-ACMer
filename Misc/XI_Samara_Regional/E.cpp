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
    if (s == t) return cout << "YES" << endl, 0;
    int n = s.length();
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
        {
            l = i;
            break;
        }
    for (int i = n - 1; ~i; i--)
        if (s[i] != t[i])
        {
            r = i + 1;
            break;
        }
    reverse(s.begin() + l, s.begin() + r);
    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
