#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg()
#endif

struct Point
{
    int x, y;
    int a, b;
    Point(int x, int y, int a, int b) : x(x), y(y), a(a), b(b) {}
    bool operator<(const Point& rhs) const
    {
        return make_pair(x, -y) < make_pair(rhs.x, -rhs.y);
    }
};

const int N = 1 << 17;
typedef long long ll;
namespace SegmentTree
{
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

ll maxv[N << 2], tag[N << 2];
inline void pushup(int o)
{
    maxv[o] = max(maxv[lson], maxv[rson]);
}
inline void pushdown(int o)
{
    if (!tag[o]) return;
    maxv[lson] += tag[o];
    maxv[rson] += tag[o];
    tag[lson] += tag[o];
    tag[rson] += tag[o];
    tag[o] = 0;
}
void build(int l, int r, int o)
{
    maxv[o] = tag[o] = 0;
    if (l == r) return;
    const int m = l + r >> 1;
    build(Lson);
    build(Rson);
}
void update(int L, int R, ll v, int l, int r, int o)
{
    if (L <= l && r <= R)
    {
        maxv[o] += v;
        tag[o] += v;
        return;
    }
    pushdown(o);
    const int m = l + r >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(o);
}
void update(int p, ll v, int l, int r, int o)
{
    if (l == r)
    {
        maxv[o] = v;
        return;
    }
    pushdown(o);
    const int m = l + r >> 1;
    if (p <= m)
        update(p, v, Lson);
    else
        update(p, v, Rson);
    pushup(o);
}
ll query(int L, int R, int l, int r, int o)
{
    if (L <= l && r <= R) return maxv[o];
    pushdown(o);
    const int m = l + r >> 1;
    ll ans = LONG_LONG_MIN;
    if (L <= m) ans = max(ans, query(L, R, Lson));
    if (m < R) ans = max(ans, query(L, R, Rson));
    return ans;
}
} // namespace SegmentTree

using namespace SegmentTree;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        vector<Point> vec;
        vector<int> vy;
        for (int i = 0, x, y, a, b; i < n; i++)
        {
            scanf("%d%d%d%d", &x, &y, &a, &b);
            vec.emplace_back(x, y, a, b);
            vy.push_back(y);
        }
        vy.push_back(0);
        sort(vy.begin(), vy.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());
        sort(vec.begin(), vec.end());
        int m = vy.size();
        build(1, m, 1);
        for (int i = 0; i < n; i++)
        {
            int y = lower_bound(vy.begin(), vy.end(), vec[i].y) - vy.begin() + 1;
            ll x = query(1, y, 1, m, 1);
            update(y, x + vec[i].b, 1, m, 1);
            if (y > 1) update(1, y - 1, vec[i].a, 1, m, 1);
            if (y < m) update(y + 1, m, vec[i].b, 1, m, 1);
        }
        printf("%lld\n", query(1, m, 1, m, 1));
    }
}