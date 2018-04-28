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

int find1(const vector<int>& v, int t)
{
    int l = 0, r = v.size() - 1;
    int ret = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (v[m] <= t)
            ret = m, l = m + 1;
        else
            r = m - 1;
    }
    return ret;
}

int find2(const vector<int>& v, int t)
{
    int l = 0, r = v.size() - 1;
    int ret = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (v[m] >= t)
            ret = m, r = m - 1;
        else
            l = m + 1;
    }
    return ret;
}
vector<int> a, b, c;

void dfs(int id, int d, ll now, ll& tmp)
{
    if (d == 0)
    {
        int p1 = find1(b, a[id]);
        int p2 = find2(b, a[id]);
        if (~p1) dfs(p1, 1, now + 1 + a[id] - b[p1], tmp);
        if (~p2) dfs(p2, 1, now + 1 + b[p2] - a[id], tmp);
    }
    if (d == 1)
    {
        int p1 = find1(c, b[id]);
        int p2 = find2(c, b[id]);
        if (~p1) dfs(p1, 2, now + 1 + b[id] - c[p1], tmp);
        if (~p2) dfs(p2, 2, now + 1 + c[p2] - b[id], tmp);
    }
    if (d == 2)
    {
        tmp = min(tmp, now + 1);
        return;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        a.resize(n), b.resize(m), c.resize(k);
        for (auto& t : a) cin >> t;
        for (auto& t : b) cin >> t;
        for (auto& t : c) cin >> t;
        ll ans = 1e18;
        for (int i = 0; i < n; i++) dfs(i, 0, 0, ans);
        cout << ans << endl;
    }
    return 0;
}
