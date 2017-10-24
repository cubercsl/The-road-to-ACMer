// 吉哥系列故事——恨7不成妻, HDU4507

/*Sample Input
3
1 9
10 11
17 17
*/

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

int a[20];
ll Pow[20];
struct Node
{
    ll cnt, sum, square;
    Node(int c = 0, int s = 0, int sq = 0) : cnt(c), sum(s), square(sq) {}
};
Node dp[20][10][10][2];
bool vis[20][10][10][2];
void init()
{
    clr(vis, 0);
    clr(dp, 0);
    Pow[0] = 1;
    for (int i = 1; i < 19; i++) Pow[i] = Pow[i - 1] * 10;
}
Node dfs(int pos, int remain = 0, int sum = 0, bool state = 0, bool limit = true)
{
    if (pos == -1) return Node(!state && remain && sum, 0, 0);
    if (!limit && vis[pos][remain][sum][state]) return dp[pos][remain][sum][state];
    Node ans;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
    {
        Node tmp = dfs(pos - 1, (remain * 10 + i) % 7, (sum + i) % 7, state | (i == 7), limit && i == a[pos]);
        ll pre = i * Pow[pos] % mod;
        (ans.cnt += tmp.cnt) %= mod;
        (ans.sum += tmp.sum + pre * tmp.cnt) %= mod;
        (ans.square += tmp.square + pre * pre % mod * tmp.cnt + 2 * pre * tmp.sum) %= mod;
    }
    if (!limit)
        vis[pos][remain][sum][state] = true, dp[pos][remain][sum][state] = ans;
    return ans;
}

ll solve(ll x)
{
    int pos = 0;
    do
        a[pos++] = x % 10;
    while (x /= 10);
    return dfs(pos - 1).square;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin init();
    int T;
    cin >> T;
    while (T--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (solve(r) - solve(l - 1) + mod) % mod << endl;
    }
    return 0;
}
