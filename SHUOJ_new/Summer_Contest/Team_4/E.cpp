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
const double eps = 1e-6;

const int maxn = 50005;
struct node
{
    int d, s, e;
    bool operator<(const node& rhs) const
    {
        return d < rhs.d || (d == rhs.d && e < rhs.e);
    }
} a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &a[i].d, &a[i].s, &a[i].e);
        sort(a, a + m);
        int cnt = 0, day = 0, cur = 0;
        for (int i = 0; i < m; i++)
            if (day < a[i].d || (day == a[i].d && cur <= a[i].s))
                cnt++, day = a[i].d, cur = a[i].e;
        printf("Scenario #%d:\n%d\n\n", ++kase, cnt);
    }
    return 0;
}
