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
    char g[1 << 17];
    while (cin >> s)
    {
        int n = s.length();
        g[n] = 'z';
        for (int i = n - 1; ~i; i--)
            g[i] = min(g[i + 1], s[i]);
        stack<char> st;
        int cur = 0;
        while (!st.empty() || cur < n)
        {
            if (!st.empty() && st.top() <= g[cur])
                cout << st.top(), st.pop();
            else
                st.push(s[cur++]);
        }
        cout << endl;
    }
    return 0;
}
