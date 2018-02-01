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

const int maxn = 1 << 17;
bool vis[maxn];
int p[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        clr(vis, 0);
        vector<ll> v;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
            {
                vis[i] = true;
                int cnt = 1;
                int cur = p[i];
                vis[cur] = true;
                while (cur != i)
                    cur = p[cur], vis[cur] = true, cnt++;
                v.pb(cnt);
                // cout << cnt <<endl;
            }
        sort(v.begin(), v.end());
        ll ans = n;
        if (v.size() > 1)
        {
            // cout << "fuck" <<endl;
            for (int i = 0; i < v.size() - 2; i++)
                ans += v[i] * (v[i] - 1);
            int a = v.size() - 1, b = a - 1;
            ans += (v[a] + v[b]) * (v[a] + v[b] - 1);
        }
        else
            ans += v[0] * (v[0] - 1);
        cout << ans << endl;
    }
    return 0;
}
