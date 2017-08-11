// Fruit, HDU2152

/*Sample Input
2 3
1 2
1 2
3 5
0 3
0 3
0 3
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

const int maxn = 105;
int a[maxn];
int b[maxn];
int c[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    while (cin >> n >> m)
    {
        clr(b, 0);
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
            b[i] = 1;
        for (int i = 1; i < n; i++)
        {
            clr(a, 0);
            clr(c, 0);
            cin >> l >> r;
            for (int i = l; i <= r; i++)
                a[i] = 1;
            for (int i = 0; i <= m; i++)
                for (int j = 0; j <= m; j++)
                    if (i + j <= m)
                        c[i + j] += (a[i] * b[j]);
            for (int i = 0;  i <= m; i++)
                b[i] = c[i];
        }
        cout << c[m] << endl;
    }
    return 0;
}
