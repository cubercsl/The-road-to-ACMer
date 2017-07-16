// Pseudo-Random Numbers, UVa350

/*Sample Input
7 5 12 4
5173 3849 3279 1511
9111 5309 6000 1234
1079 2136 9999 1237
0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e4 + 5;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int z, i, m, l;
    bool vis[maxn];
    int kase = 0;
    while (cin >> z >> i >> m >> l, z + i + m + l)
    {
        clr(vis, 0);
        int cnt = 0;
        while (++cnt)
        {
            l = (z * l + i) % m;
            if (vis[l])
                break;
            vis[l] = 1;
        }
        if (l)
            cout << "Case " << ++kase << ": " << cnt - 1 << endl;
    }
    return 0;
}
