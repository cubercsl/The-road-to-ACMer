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

int ans, n, a, b, s[6];
void dfs(int pos, int cnt, VI ret)
{
    if (pos == 6)
    {
        ans = min(ans, cnt);
        return;
    }
    for (auto& t : ret)
    {
        if (t >= s[pos])
        {
            t -= s[pos];
            dfs(pos + 1, cnt, ret);
            t += s[pos];
        }
    }
    ret.pb(n - s[pos]);
    dfs(pos + 1, cnt + 1, ret);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> a >> b)
    {
        for (int i = 0; i < 4; i++) s[i] = a;
        s[4] = s[5] = b;
        ans = INF;
        VI ret;
        dfs(0, 0, ret);
        cout << ans << endl;
    }
    return 0;
}
