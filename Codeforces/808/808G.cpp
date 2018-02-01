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

string s, t;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> s >> t)
    {
        int n = s.length(), m = t.length();
        int cnt = 0;
        for (int i = 0; i + m < n; i++)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (s[i + j] == '?') continue;
                if (s[i + j] != t[i]) break;
            }
            if (j == m) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
