// Can you answer these queries?, HDU4027

/*Sample Input
10
1 2 3 4 5 6 7 8 9 10
5
0 1 10
1 1 10
1 1 5
0 5 8
1 4 8
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

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int maxn = 1e5 + 5;
ll sum[maxn << 2];
bool flag[maxn << 2];

void PushUp(int rt)
{
    sum[rt] = sum[lson] + sum[rson];
    flag[rt] = flag[lson] | flag[rson];
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        flag[rt] = sum[rt] != 1;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}

void update(int L, int R, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = (ll) sqrt(sum[rt]);
        if (sum[rt] == 1) flag[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m && flag[lson]) update(L, R, Lson);
    if (m < R && flag[rson]) update(L, R, Rson);
    PushUp(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sum[rt];
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, kase = 0;
    while (~scanf("%d", &n))
    {
        build(1, n, 1);
        int m;
        scanf("%d", &m);
        printf("Case #%d:\n", ++kase);
        while (m--)
        {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            if (x > y)
                swap(x, y);
            if (t)
                printf("%lld\n", query(x, y, 1, n, 1));
            else
                update(x, y, 1, n, 1);
        }
        printf("\n");
    }
    return 0;
}
