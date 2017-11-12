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

const int maxn = 1e6 + 5;

int dp[maxn];

int find(int n)
{
    for (int i = 0; i < maxn; i++)
        if (dp[i] == n) return i;
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(dp, 0);
    dp[0] = 1;
    for (int i = 1; i <= 2; i++)
        for (int j = i; j < maxn; j++)
            dp[j] += dp[j - i];
    // for (int i = 0; i < maxn; i++)
    // cout << dp[i] << endl;
    int n;
    while (cin >> n)
    {
        if (n == 1)
        {
            cout << 1 << " " << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        int ans = find(n);
        assert(ans > 0);
        cout << ans << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
    return 0;
}
