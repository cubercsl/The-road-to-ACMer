#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1 << 17;
int val[N << 2];
int a[N];

#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

inline void pushup(int o)
{
    val[o] = min(val[lson], val[rson]);
}

void build(int l, int r, int o)
{
    if (l == r)
    {
        val[o] = a[l];
        return;
    }
    const int m = l + r >> 1;
    build(Lson), build(Rson);
    pushup(o);
}

void update(int p, int l, int r, int o)
{
    if (l == r)
    {
        val[o] = INF;
        return;
    }
    const int m = l + r >> 1;
    if (p <= m)
        update(p, Lson);
    else
        update(p, Rson);
    pushup(o);
}

bool flag;

pair<int, int> query(int L, int R, int v, int l, int r, int o)
{
    if (l == r)
    {
        flag = true;
        return make_pair(l, val[o]);
    }
    const int m = l + r >> 1;
    if (L <= m && val[lson] <= v) return query(L, R, v, Lson);
    if (m < R && val[rson] <= v) return query(L, R, v, Rson);
    return make_pair(0, 0);
}

int rep[N], rem[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, n, 1);
    int cnt = 0, day = 1, now = 0;
    for (; day <= 100001; day++)
    {
        now += m;
        int pos = 1;
        while (pos <= n)
        {
            flag = false;
            auto ret = query(pos, n, now, 1, n, 1);
            if (flag)
            {
                cnt++;
                pos = ret.first;
                now -= ret.second;
                update(pos, 1, n, 1);
                pos++;
            }
            else
                break;
        }
        rep[day] = cnt;
        rem[day] = now;
        if (cnt == n) break;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int d;
        scanf("%d", &d);
        d = min(d, day);
        printf("%d %d\n", rep[d], rem[d]);
    }
}