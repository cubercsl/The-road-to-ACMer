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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, p;
    cin >> n >> p;
    vector<int> a(n << 1);
    for (auto& t : a) cin >> t;
    queue<int> q;
    vector<int> d(100, -1), path(100, -1);
    q.push(0);
    d[0] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto& x : a)
        {
            int tt = (t + x) % 100;
            if (~d[tt]) continue;
            d[tt] = d[t] + 1;
            path[tt] = t;
            q.push(tt);
        }
    }
    for (int i = 0; i < 365; i++)
    {
        if (p == 0) return 0;
        vector<int> id(n);
        for (auto& t : id) cin >> t, --t;
        if (p == 100)
        {
            cout << 0 << " " << id[0] + 1 << endl;
            p -= a[id[0]];
            continue;
        }
        assert(~path[p]);
        int x = p - path[p], c = 0;
        if (x < 0) c = 1, x += 100;
        assert(x < 100);
        int ans = -1;
        for (auto& t : id)
            if (a[t] == x)
            {
                ans = t;
                break;
            }
        if (~ans)
            p = path[p], cout << c << " " << ans + 1 << endl;
        else
            cout << 0 << " " << 0 << endl;
    }
    return 0;
}