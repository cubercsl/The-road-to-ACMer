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

PII operator-(const PII& a, const PII& b)
{
    return mp(a.X - b.X, a.Y - b.Y);
}

bool judge(PII a, PII b, PII c)
{
    PII aa = b - a, bb = c - a;
    return (1LL * aa.X * bb.Y - 1LL * aa.Y * bb.X) == 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    srand(time(0));
    int n;
    cin >> n;
    vector<PII> v(n);
    for (auto& t : v) cin >> t.X >> t.Y;
    if (n < 5) return cout << "YES", 0;

    int T = 100;
    while (T--)
    {
        vector<int> vis(n);
        random_shuffle(v.begin(), v.end());
        // 0-1
        vis[0] = vis[1] = 1;
        for (int i = 1; i < n; i++)
            if (judge(v[0], v[1], v[i])) vis[i] = 1;
        // for (auto& t : vis) cout << t;
        // cout << endl;
        int x = 0, y = 0;
        while (x < n && vis[x]) x++;
        y = x + 1;
        while (y < n && vis[y]) y++;
        if (x == n || y == n) return cout << "YES", 0;
        for (int i = 0; i < n; i++)
            if (judge(v[x], v[y], v[i])) vis[i] = 1;
        y = 0;
        while (y < n && vis[y]) y++;
        if (y == n) return cout << "YES", 0;
    }
    cout << "NO";
    return 0;
}