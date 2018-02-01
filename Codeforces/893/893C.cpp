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

const int N = 1 << 17;
int fa[N], val[N];
inline int init(int n)
{
    for (int i = 0; i < n; i++) fa[i] = i;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    fa[y] = x;
    val[x] = min(val[x], val[y]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        init(n);
        for (int i = 0; i < n; i++) scanf("%d", &val[i]);
        while (m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            unite(u, v);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i)
                ans += (ll)val[i];
        printf("%lld\n", ans);
    }
    return 0;
}
