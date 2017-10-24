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
    int n;
    bool vis[10];
    string s, t;
    cin >> n;
    for (int _ = 0; _ < 5; _++)
    {
        cin >> s >> t;
        int ans = 0;
        clr(vis, 0);
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int c = s[i] - '0';
            if (vis[c]) continue;
            if (s[i] == t[i]) continue;
            int cur = i;
            while (vis[c] == 0)
            {
                // cout << c << endl;
                cnt++;
                vis[c] = 1;
                for (int j = 0; j < n; j++)
                    if (t[j] == s[cur])
                    {
                        cur = j;
                        break;
                    }
                c = s[cur] - '0';
            }
            //  cout << cnt << endl;
            // cout << i << " " << cnt << endl;
            if (i == 0)
                ans += cnt - 1;
            else
                ans += cnt + 1;
        }
        cout << ans << endl;
        // cout << endl;
    }
    return 0;
}
