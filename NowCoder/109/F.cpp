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
const int N = 1 << 20;
int f[N];
void initkmp(const string& x)
{
    int m = x.length();
    int i = 0, j = f[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = f[j];
        f[++i] = ++j;
    }
}

int kmp(const string& x, const string& y)
{
    VI ans;
    int i, j;
    int m = x.length(), n = y.length();
    i = j = 0;
    initkmp(x);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = f[j];
        i++, j++;
        if (j >= m) ans.push_back(i - m), j = f[j];
    }
    // for(auto& t : ans) cout << t << " ";
    // cout << endl;
    int op = INF;
    if (ans.empty()) return -1;
    if (ans.size() == 1)
        op = min(ans[0] + 1, n - m - ans[0] + 1);
    else
    {
        for (int i = 0; i + 1 < ans.size(); i++)
            op = min(op, ans[i] + 1 + n - ans[i + 1] - m + 1);
    }
    return op;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int ans = kmp(t, s);
        int d = s.length() - t.length();
        int can = d - (d >> 1);
        // cout << ans << endl;
        if (can >= ans)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }

    return 0;
}
