// Count the Colors, ZOJ1610

/*Sample Input

5
0 4 4
0 3 1
3 4 2
0 2 2
0 2 3
4
0 1 1
3 4 1
1 3 2
1 3 1
6
0 1 0
1 2 1
2 3 1
1 2 0
2 3 0
1 2 1
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
const int maxn = 8005;
const int N = 8000;
int val[maxn << 2];
int vis[maxn];

void build(int l, int r, int rt)
{
    val[rt] = -1;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void PushDown(int rt)
{
    if (val[rt] == -1)
        return;
    val[lson] = val[rson] = val[rt];
    val[rt] = -1;
}

void update(int L, int R, int setv, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        val[rt] = setv;
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, setv, Lson);
    if (m < R) update(L, R, setv, Rson);
}

int query(int p, int l, int r, int rt)
{
    if (l == r) return val[rt];
    PushDown(rt);
    int m = (l + r) >> 1;
    if (p <= m) return query(p, Lson);
    if (m < p) return query(p, Rson);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        clr(vis, 0);
        build(0, N, 1);
        while (n--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, --b, c, 0, N, 1);
        }
        int ans = 0, tmp = -1;
        for (int i = 0; i <= N; i++)
        {
            int col = query(i, 0, N, 1);
            if (col != -1 && col != tmp)
                vis[col]++;
            tmp = col;
        }
        for (int i = 0; i <= N; i++)
        {
            if (vis[i])
                printf("%d %d\n", i, vis[i]);
        }
        printf("\n");
    }
    return 0;
}
