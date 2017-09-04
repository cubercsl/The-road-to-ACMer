// Color it, HDU6183

/*Sample Input
0
1 1000000 1000000 50
1 1000000 999999 0
1 1000000 999999 0
1 1000000 1000000 49
2 1000000 1000000 1000000
2 1000000 1 1000000
0
1 1 1 1
2 1 1 2
1 1 2 2
2 1 1 2
1 2 2 2
2 1 1 2
1 2 1 3
2 2 1 2
2 10 1 2
2 10 2 2
0
1 1 1 1
2 1 1 1
1 1 2 1
2 1 1 2
1 2 2 1
2 1 1 2
1 2 1 1
2 2 1 2
2 10 1 2
2 10 2 2
3
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

#define Lson l, m, lson[rt]
#define Rson m + 1, r, rson[rt]

const int maxn = 1e6 + 5;
int minv[maxn << 2], lson[maxn << 2], rson[maxn << 2];
int tot, rt[55];

void init()
{
    tot = 0;
    clr(rt, 0);
    clr(lson, 0);
    clr(rson, 0);
}

void update(int p, int v, int l, int r, int &rt)
{
    if (rt == 0)
        rt = ++tot, minv[rt] = v;
    minv[rt] = min(minv[rt], v);
    if (l == r) return;
    int m = (l + r) >> 1;
    if (p <= m) update(p, v, Lson);
    if (m < p) update(p, v, Rson);
}

bool flag;
void query(int L, int R, int v, int l, int r, int rt)
{
    if (flag || rt == 0) return;
    if (L <= l && r <= R)
    {
        if (minv[rt] <= v)
            flag = true;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) query(L, R, v, Lson);
    if (m < R) query(L, R, v, Rson);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int cmd, x, y, c, y1, y2;
    const int n = 1e6;
    while (~scanf("%d", &cmd), cmd != 3)
    {
        if (cmd == 0)
            init();
        if (cmd == 1)
        {
            scanf("%d%d%d", &x, &y, &c);
            update(y, x, 1, n, rt[c]);
        }
        if (cmd == 2)
        {
            int ans = 0;
            scanf("%d%d%d", &x, &y1, &y2);
            for (int i = 0; i <= 50; i++)
            {
                flag = false;
                query(y1, y2, x, 1, n, rt[i]);
                ans += flag;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
