// Dragon of Loowater, UVa11292

/*Sample Input
2 3
5
4
7
8
4
2 1
5
5
10
0 0
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

const int maxn = 2e5 + 5;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    int v[maxn], p[maxn];
    while (cin >> n >> m, m + n)
    {
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < m; i++)
            cin >> p[i];
        sort(v, v + n);
        sort(p, p + m);
        int cnt = 0;
        int vis = 0;
        for (int i = 0; i < m && vis < n; i++)
        {

            if (p[i] >= v[vis])
            {
                cnt += p[i];
                vis++;
            }
        }
        if (vis == n)
            cout << cnt << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }
    return 0;
}
