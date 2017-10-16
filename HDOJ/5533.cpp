// Dancing Stars on Me, HDU5533

/*Sample Input
3
3
0 0
1 1
1 0
4
0 0
0 1
1 0
1 1
5
0 0
0 1
0 2
2 2
2 0
*/

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

PII a[4];

inline ll dis2(PII a, PII b)
{
    ll dx = a.X - b.X, dy = a.Y - b.Y;
    return dx * dx + dy * dy;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, buf;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n != 4)
        {
            puts("NO");
            for (int i = 0; i < (n << 1); i++)
                scanf("%d", &buf);
            continue;
        }
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].X, &a[i].Y);
        vector<ll> v;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                v.pb(dis2(a[i], a[j]));
        sort(v.begin(), v.end());
        puts(v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5] && v[4] == 2 * v[3] ? "YES" : "NO");
    }
    return 0;
}
