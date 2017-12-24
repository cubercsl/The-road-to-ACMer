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

PII a[105];
bool solve(int n)
{
    if (a[0].X != 0) return false;
    int pos = a[0].Y;
    for (int i = 1; i < n; i++) {
        if (a[i].X > pos) return false;
        pos = max(a[i].Y, pos);
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (cur >= x) cur = max(cur, y);
        }
        if (cur >= m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
