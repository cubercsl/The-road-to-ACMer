// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e3 + 5;
int a[maxn], b[maxn], c[maxn];
int dp[maxn][305];
int n, m, k, l;
map<int, int> id;
int dfs(int pos, int sco)
{
    if (pos == n + 1)
    {
        if (sco >= k)
            return 2;
        else if (sco <= l)
            return 0;
        else
            return 1;
    }
    if (dp[pos][id[sco]] != -1) return dp[pos][id[sco]];
    if (pos & 1)
    {
        int ret = 0;
        int tmp = sco;
        tmp = min(100, sco + a[pos]);
        if (a[pos]) ret = max(ret, dfs(pos + 1, tmp));
        tmp = max(-100, sco + b[pos]);
        if (b[pos]) ret = max(ret, dfs(pos + 1, tmp));
        if (c[pos]) ret = max(ret, dfs(pos + 1, -sco));
        return dp[pos][id[sco]] = ret;
    }
    else
    {
        int ret = 2;
        int tmp = sco;
        tmp = min(100, sco + a[pos]);
        if (a[pos]) ret = min(ret, dfs(pos + 1, tmp));
        tmp = max(-100, sco + b[pos]);
        if (b[pos]) ret = min(ret, dfs(pos + 1, tmp));
        if (c[pos]) ret = min(ret, dfs(pos + 1, -sco));
        return dp[pos][id[sco]] = ret;
    }
}
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int cnt = 0;
    for (int i = -100; i <= 100; i++) id[i] = ++cnt;
    scanf("%d%d%d%d", &n, &m, &k, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", a + i, b + i, c + i);
        b[i] = -b[i];
    }
    clr(dp, -1);
    int op = dfs(1, m);
    if (op == 2)
        puts("Good Ending");
    else if (op == 1)
        puts("Normal Ending");
    else
        puts("Bad Ending");
}