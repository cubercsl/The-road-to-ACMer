#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 10005;
int n, a, b;
int num[maxn];
int dp[maxn];
int dfs(int m)
{
    if (dp[m] != NINF) return dp[m];
    int ans = NINF;
    for (int i = m + 1; i < n; i++)
        if (num[i] - num[m] >= a && num[i] - num[m] <= b)
            ans = max(ans, dfs(i));
    if (ans == NINF) return dp[m] = num[m];
    return dp[m] = num[m] - ans;
}

int solve()
{
    int ans = NINF;
    for (int i = 0; i < n; i++)
        if (num[i] >= a && num[i] <= b)
            ans = max(ans, dfs(i));
    return ans == NINF ? 0 : ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        for (int i = 0; i < n; i++)
            cin >> num[i];
        clr(dp, 0xc0);
        sort(num, num + n);
        cout << solve() << endl;
    }
    return 0;
}
