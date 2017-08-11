// Classes, 2017 Multi-University Training Contest, HDU6106

/*Sample Input
2
2
4 5 4 4 3 2 2
5 3 1 2 0 0 0
2
0 4 10 2 3 4 9
6 12 6 3 5 3 2
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    scanf("%d", &t);
    int a, b, c, d, e, f, g;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int ans = 0, tmp = 0;
        while (n--)
        {
            scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
            tmp = a + b + c - d - e - f + g;
            if (tmp < 0)continue;
            if (a + g - d - f < 0)continue;
            if (b + g - d - e < 0)continue;
            if (c + g - e - f < 0)continue;
            if (d - g < 0)continue;
            if (e - g < 0)continue;
            if (f - g < 0)continue;
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
