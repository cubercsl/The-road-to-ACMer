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

typedef pair<ll, PII> Node;
inline ll calc(const int& x, const int& y, const int& n, const int& m, const int& r)
{
    return 1LL * min(min(x, n - x + 1), r) * min(min(y, m - y + 1), r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, r, k;
    while (cin >> n >> m >> r >> k)
    {
        priority_queue<Node> q;
        set<PII> s;
        int x = (n + 1) / 2, y = (m + 1) / 2;
        ll val = calc(x, y, n, m, r);
        q.push({val, {x, y}});
        s.insert({x, y});

        ll ans = 0;
        int cnt = 0;
        while (!q.empty())
        {
            Node tmp = q.top();
            q.pop();
            ans += tmp.X;
            if (++cnt == k) break;
            PII& loc = tmp.Y;
            int &x = loc.X, &y = loc.Y;
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                    if (i || j)
                    {
                        int dx = x + i, dy = y + j;
                        if (dx <= 0 || dy <= 0 || dx > n || dy > m) continue;
                        if (s.find({dx, dy}) != s.end()) continue;
                        s.insert({dx, dy});
                        q.push({calc(dx, dy, n, m, r), {dx, dy}});
                    }
        }
        cout << ans << endl;
    }
    return 0;
}
