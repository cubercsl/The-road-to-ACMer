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

int a[40];
int n, m;
vector<int> v[2];

void dfs(int id, int cur, bool flag)
{
    if (flag == 0 && id == n / 2)
    {
        v[0].pb(cur);
        return;
    }
    if (flag == 1 && id == n)
    {
        v[1].pb(cur);
        return;
    }
    dfs(id + 1, (cur + a[id]) % m, flag);
    dfs(id + 1, cur, flag);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin while (cin >> n >> m)
    {
        v[0].clear(), v[1].clear();
        for (int i = 0; i < n; i++)
            cin >> a[i];
        dfs(0, 0, 0);
        dfs(n / 2, 0, 1);
        // cout << "here" << endl;
        int ans = 0;
        for (int i = 0; i < 2; i++) sort(v[i].begin(), v[i].end());
        for (int i = 0; i < v[0].size(); i++)
        {
            ans = max(ans, (v[0][i] + *v[1].rbegin()) % m);
            auto p = upper_bound(v[1].begin(), v[1].end(), m - v[0][i] - 1);
            if (p == v[1].begin()) continue;
            p--;
            ans = max(ans, (v[0][i] + *p) % m);
        }
        cout << ans << endl;
    }
    return 0;
}
