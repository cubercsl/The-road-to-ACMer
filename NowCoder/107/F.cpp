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
    int n, m, q;
    while (cin >> n >> m >> q)
    {
        bool d = 0;
        set<int> s[2];
        int ans = 0;
        while (q--)
        {
            static int c;
            cin >> c;
            if (s[d ^ 1].find(c) == s[d ^ 1].end())
            {
                if (s[d].find(c) == s[d].end()) ans++;
                s[d ^ 1].insert(c);
            }
            if (s[d ^ 1].size() == m) s[d].clear(), d ^= 1;
        }
        cout << ans << endl;
    }
    return 0;
}