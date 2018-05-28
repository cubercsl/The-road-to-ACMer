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

const int N = 1 << 17;
int deg[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }
    int cnt = 0;
    VI ans;
    for (int i = 1; i <= n; i++)
        if (deg[i] > 2)
            cnt++;
        else if (deg[i] == 1)
            ans.pb(i);
    if (cnt > 1) return cout << "No", 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] > 2)
        {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (auto& t : ans) cout << i << " " << t << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << 1 << endl;
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}