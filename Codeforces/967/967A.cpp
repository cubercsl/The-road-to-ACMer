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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0, h, m; i < n; i++)
    {
        cin >> h >> m;
        a[i] = h * 60 + m;
    }
    a.push_back(INF);
    if (a[0] > s)
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i + 1] - a[i] <= s) continue;
        if (a[i + 1] - (a[i] + 1 + s) > s)
        {
            int hh = (a[i] + s + 1) / 60, mm = (a[i] + s + 1) % 60;
            cout << hh << " " << mm << endl;
            return 0;
        }
    }
    return 0;
}
