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

int ok(int x, const int& m, const int& tar, const vector<PII>& v)
{
    int cnt = 0, cur = m, sum = 0;
    for (auto& t : v)
    {
        if (t.Y >= x && t.X <= cur)
            cur -= t.X, sum += t.Y, cnt++;
    }
    if (cnt == tar) return sum;
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        vector<PII> v(n);
        for (auto& t : v) cin >> t.X >> t.Y;
        sort(v.begin(), v.end());
        int cnt = 0;
        int cur = m;
        for (auto& t : v)
        {
            if (t.X <= cur)
                cnt++, cur -= t.X;
            else
                break;
        }
        int L = 0, R = 1e4, ans;
        while (L <= R)
        {
            int mid = L + R >> 1;
            if (~ok(mid, m, cnt, v))
                ans = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        cout << cnt << " " << ok(ans, m, cnt, v) << endl;
    }
    return 0;
}
