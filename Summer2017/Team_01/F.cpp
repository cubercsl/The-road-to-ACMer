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

const int maxn = 1e5 + 5;
double a[maxn];

bool cmp(double a, double b)
{
    return a > b;
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            scanf("%lf", a + i);
        int u, v;
        double w;
        while (m--)
        {
            scanf("%d%d%lf", &u, &v, &w);
            w *= 0.5;
            a[u] += w, a[v] += w;
        }
        sort(a + 1, a + n + 1, cmp);
        double ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                ans += a[i];
            else
                ans -= a[i];
        }
        printf("%.0f\n", ans);
    }
    return 0;
}
