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

const int maxn = 1 << 17;
int dp[maxn];
map<int, int> m;
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n;
    string s;
    while (cin >> n)
    {
        m.clear();
        for (int i = -n; i <= n; i++)
            m[i] = -1;
        cin >> s;
        int cur = 0;
        m[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cur++;
            else
                cur--;
            dp[i + 1] = cur;
            if (m[cur] == -1) m[cur] = i + 1;
        }
        // for (int i = 0; i <= n; i++) cout << dp[i] << endl;
        // for (int i = 0; i <= n; i++) cout << m[i] << endl;
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            int pos = m[dp[i]];
            if (~pos)
                ans = max(ans, i - pos);
        }
        cout << ans << endl;
    }
    return 0;
}
