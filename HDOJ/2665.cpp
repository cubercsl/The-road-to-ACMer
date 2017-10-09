// Kth number, HDU2665

/*Sample Input
1
10 1
1 4 2 3 5 6 7 8 9 0
1 3 2
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

const int maxn = 1 << 17;
int a[maxn], rt[maxn];
vector<int> v;
int cnt;
int lson[maxn << 5], rson[maxn << 5], sum[maxn << 5];
#define Lson l, m, lson[x], lson[y]
#define Rson m + 1, r, rson[x], rson[y]

void update(int p, int l, int r, int& x, int y)
{
    lson[++cnt] = lson[y], rson[cnt] = rson[y], sum[cnt] = sum[y] + 1, x = cnt;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, Lson);
    else
        update(p, Rson);
}

int query(int l, int r, int x, int y, int k)
{
    if (l == r) return l;
    int m = (l + r) >> 1;
    int s = sum[lson[y]] - sum[lson[x]];
    if (s >= k)
        return query(Lson, k);
    else
        return query(Rson, k - s);
}

inline int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        v.clear(), cnt = 0;
        rt[0] = sum[0] = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", a + i), v.pb(a[i]);
        sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i++) update(getid(a[i]),1, n, rt[i], rt[i - 1]);
        while (m--)
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            printf("%d\n", v[query(1, n, rt[x - 1], rt[y], k) - 1]);
        }
    }
    return 0;
}
