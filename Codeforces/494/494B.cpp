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
int ne[maxn];
int val[maxn];
void initkmp(const string& x)
{
    int m = x.length();
    int i, j;
    j = ne[0] = -1;
    i = 0;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}
void kmp(const string& x, const string& y)
{
    int m = x.length(), n = y.length();
    int i, j, ans;
    i = j = ans = 0;
    initkmp(x);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = ne[j];
        i++, j++;
        if (j >= m)
        {
            val[i] = i - m + 1;
            j = ne[j];
        }
    }
}

ll dp[maxn];
ll presum[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    string s, t;
    while (cin >> s >> t)
    {
        clr(val, 0);
        int n = s.length();
        kmp(t, s);
        // for (int i = 1; i <= s.length(); i++)
        //     cout << val[i] << endl;
        for (int i = 1; i <= n; i++)
        {
            if (!val[i]) val[i] = val[i - 1];
            dp[i] = (dp[i - 1] + presum[val[i] - 1] + val[i]) % mod;
            presum[i] = (presum[i - 1] + dp[i]) % mod;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
