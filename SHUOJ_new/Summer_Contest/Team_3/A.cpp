#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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

int n, m;
const int maxn = 60005;
struct node
{
    int x, y;
    bool operator<(const node& rhs) const
    {
        return x < rhs.x || (x == rhs.x && y > rhs.y);
    }
} a[maxn];

int bit[maxn];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    for (int i = x; i <= n + m; i += lowbit(i))
        bit[i]++;
}

ll query(int x)
{
    ll sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += bit[i];
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        clr(bit, 0);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n + m; i++)
            scanf("%d%d", &a[i].x, &a[i].y);
        sort(a, a + n + m);
        ll ans = 0;
        for (int i = 0; i < n + m; i++)
        {
            ans += query(n + m) - query(a[i].y - 1);
            update(a[i].y);
        }
        printf("Scenario #%d:\n", ++kase);
        printf("%lld\n\n", ans);
    }
    return 0;
}
