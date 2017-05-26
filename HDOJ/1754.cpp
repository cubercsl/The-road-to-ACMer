// I Hate It, HDU1754

/*Sample Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5
*/

#include <bits/stdc++.h>
using namespace std;
#define Lson 2 * node
#define Rson 2 * node + 1

const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int MAXN = 4e5 + 10;
int t;
int input[MAXN];
int segtree[MAXN];
void build(int L, int R, int node)
{
    if (L == R)
    {
        segtree[node] = input[L];
        return;
    }
    int mid = (L + R) / 2;
    build(L, mid, Lson);
    build(mid + 1, R, Rson);
    segtree[node] = max(segtree[Lson], segtree[Rson]);
}

void update(int pos, int val)
{
    int node = pos + t - 1;
    segtree[node] = val;
    while (node > 1)
    {
        node >>= 1;
        segtree[node] = max(segtree[Lson], segtree[Rson]);
    }
}

int query(int x, int y, int L, int R, int node)
{
    int mid = L + (R - L) / 2, ans = NINF;
    if (x <= L && R <= y)
        return segtree[node];
    if (x <= mid)
        ans = max(ans, query(x, y, L, mid, Lson));
    if (mid < y)
        ans = max(ans, query(x, y, mid + 1, R, Rson));
    return ans;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(input, 0xc0, sizeof(input));
        for (int i = 1; i <= n; i++)
            scanf("%d", &input[i]);
        t = 1;
        while (t < n)
            t <<= 1;
        build(1, t, 1);
        while (m--)
        {
            char cmd;
            int x, y;
            getchar();
            scanf("%c", &cmd);
            getchar();
            scanf("%d%d", &x, &y);
            if (cmd == 'U')
                update(x, y);
            else
                printf("%d\n", query(x, y, 1, t, 1));
        }
    }
    return 0;
}
