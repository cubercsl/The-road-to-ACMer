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

const int N = 1 << 18;
string t, p;
int a[N];
bool vis[N];
bool ok(int m)
{
    int n = t.length();
    clr(vis, 0);
    for (int i = 0; i < m; i++) vis[a[i] - 1] = 1;
    string tmp;
    for (int i = 0; i < n; i++)
        if (!vis[i]) tmp.pb(t[i]);
    int cur = 0;
    // cout << tmp << endl;
    int len = p.length();
    n = tmp.length();
    for (int i = 0; i < len; i++)
    {
        for (; cur < n && tmp[cur++] != p[i];)
            ;
        if (cur == n)
        {
            if (i == len - 1)
                return tmp[cur - 1] == p[i];
            return false;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> t >> p)
    {
        int n = t.length();
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = n - p.length(), ans;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (ok(m))
                ans = m, l = m + 1;
            else
                r = m - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
