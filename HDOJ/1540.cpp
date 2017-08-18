// Tunnel Warfare, HDU1540

/*Sample Input
7 9
D 3
D 6
D 5
Q 4
Q 5
R
Q 4
R
Q 4
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
#define lm (m - (m >> 1))
#define rm (m >> 1)

const int maxn = 50005;
int ls[maxn << 2], rs[maxn << 2], ms[maxn << 2];

void pushup(int rt, int m)
{
    ls[rt] = ls[lson] + (ls[lson] == lm) * ls[rson];
    rs[rt] = rs[rson] + (rs[rson] == rm) * rs[lson];
    ms[rt] = max(max(ms[lson], ms[rson]), rs[lson] + ls[rson]);
}

void build(int l, int r, int rt)
{
    ls[rt] = rs[rt] = ms[rt] = r - l + 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void update(int p, int t, int l, int r, int rt)
{
    if (l == r)
    {
        ls[rt] = rs[rt] = ms[rt] = t;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, t, Lson);
    if (m < p) update(p, t, Rson);
    pushup(rt, r - l + 1);
}

int query(int p, int l, int r, int rt)
{
    if (l == r || ms[rt] == r - l + 1)
        return ms[rt];
    int m = (l + r) >> 1;
    if (p <= m)
    {
        if (p >= m - rs[lson] + 1)
            return query(p, Lson) + query(m + 1, Rson);
        return query(p, Lson);
    }
    else
    {
        if (p < m + ls[rson] + 1)
            return query(p, Rson) + query(m, Lson);
        return query(p, Rson);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, t;
    char cmd[3];
    while (~scanf("%d%d", &n, &m))
    {
        stack<int> s;
        build(1, n, 1);
        while (m--)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'R')
            {
                update(s.top(), 1, 1, n, 1);
                s.pop();
                continue;
            }
            scanf("%d", &t);
            if (cmd[0] == 'D')
            {
                s.push(t);
                update(t, 0, 1, n, 1);
            }
            else
                printf("%d\n", query(t, 1, n, 1));
        }
    }
    return 0;
}
