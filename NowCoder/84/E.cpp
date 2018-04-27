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
    cin >> n;
    vector<int> a(n);
    unordered_set<int> s;
    vector<vector<int> > dp(n + 1, vector<int>(20, -1));
    for (auto& t : a) cin >> t, s.insert(t);
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < 20; j++) dp[i][j] = dp[i + 1][j];
        for (int j = 0; j < 20; j++)
            if (a[i] >> j & 1) dp[i][j] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int now = 0;
        for (int j = i, nx; j < n; j = nx + 1)
        {
            nx = n;
            for (int k = 0; k < 20; k++)
                if (!(now >> k & 1) && ~dp[j][k]) nx = min(nx, dp[j][k]);
            if (nx < n) now |= a[nx], s.insert(now);
        }
    }
    cout << s.size() << endl;
    return 0;
}
