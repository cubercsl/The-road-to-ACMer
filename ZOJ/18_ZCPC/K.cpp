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

inline int f(const PII& a, int m)
{
    int x = a.X, y = a.Y;
    return x * m + y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    map<char, int> M;
    M['C'] = 0, M['B'] = 1, M['D'] = 2;
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<PII> v(n);
        for (int i = 0; i < n; i++)
        {
            static char c;
            static int w;
            cin >> c;
            if (c == 'W')
                v[i] = {-1, -1};
            else
            {
                cin >> w;
                v[i] = {M[c], w - 1};
            }
        }
        if (n == 1)
        {
            cout << 3 * m << endl;
        }
        else if (v[0] > v[1] && v[1] != mp(-1, -1))
        {
            cout << 1 << endl;
        }
        else if (v[0] == mp(-1, -1))
        {
            int x = v[1].X, y = v[1].Y;
            int ans = x * m + y;
            cout << ans << endl;
        }
        else
        {
            v.push_back({3, 0});
            bool bb = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == mp(-1, -1))
                {
                    int ans = f(v[i + 1], m) - f(v[i - 1], m) - 1;
                    if (i == 1) ans++;
                    bb = 1;
                    cout << ans << endl;
                    break;
                }
            }
            if (!bb) cout << 3 * m - n + 1 << endl;
        }
    }
    return 0;
}