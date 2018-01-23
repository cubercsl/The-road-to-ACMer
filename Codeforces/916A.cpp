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

bool ok(int h, int m)
{
    if (m / 10 == 7) return true;
    if (m % 10 == 7) return true;
    if (h == 7 || h == 17) return true;
    return false;
}

inline void change(int x, int& h, int& m)
{
    while (x--)
    {
        --m;
        if (m == -1)
            m = 59, --h;
        if (h == -1)
            h = 23;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int x;
    int h, m;
    while (cin >> x >> h >> m)
    {
        int cnt = 0;
        while (!ok(h, m))
        {
            cnt++;
            change(x, h, m);
        }
        cout << cnt << endl;
    }
    return 0;
}
