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

inline int dis(PII a, PII b)
{
    int dx = a.X - b.X, dy = a.Y - b.Y;
    return dx * dx + dy * dy;
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
        int n;
        cin >> n;
        vector<PII> v(n);
        vector<vector<int> > G(n);
        for (auto& t : v) cin >> t.X >> t.Y;
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int d = dis(v[i], v[j]);
                G[i].pb(d);
                G[j].pb(d);
            }
        for (int i = 0; i < n; i++)
        {
            sort(G[i].begin(), G[i].end());
            int cnt = 1;
            for (int j = 1; j < G[i].size(); j++)
            {
                if (G[i][j] == G[i][j - 1])
                    cnt++;
                else
                {
                    ans += 1LL * (cnt - 1) * cnt;
                    cnt = 1;
                }
            }
            ans += 1LL * (cnt - 1) * cnt;
        }
        if (!ans)
            cout << "WA" << endl;
        else
            cout << ans << endl;
    }
}
