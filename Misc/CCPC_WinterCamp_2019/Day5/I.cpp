#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

int a[1 << 18];
int x;
namespace Segment_Tree
{
struct Node
{
    int l, r;
    int sum, tag;
    shared_ptr<Node> lson, rson;
    Node(int l, int r) : l(l), r(r) { tag = -1; };
    int length() const { return r - l + 1; }
    void maintain() { sum = lson->sum + rson->sum; }
    void pushdown()
    {
        if (!~tag) return;
        lson->sum = (length() - (length() >> 1)) * tag;
        rson->sum = (length() >> 1) * tag;
        lson->tag = tag;
        rson->tag = tag;
        tag = -1;
    }
};
void build(int l, int r, shared_ptr<Node>& o)
{
    o = make_shared<Node>(l, r);
    if (l == r)
    {
        o->sum = a[l] > x;
        return;
    }
    const int m = l + r >> 1;
    build(l, m, o->lson);
    build(m + 1, r, o->rson);
    o->maintain();
}

void update(int l, int r, int v, shared_ptr<Node> o)
{
    if (r < l) return;
    if (l <= o->l && o->r <= r)
    {
        o->sum = v * o->length();
        o->tag = v;
        return;
    }
    o->pushdown();
    const int m = o->l + o->r >> 1;
    if (l <= m) update(l, r, v, o->lson);
    if (m < r) update(l, r, v, o->rson);
    o->maintain();
}

int query(int l, int r, shared_ptr<Node> o)
{
    if (r < l) return 0;
    if (l <= o->l && o->r <= r) return o->sum;
    o->pushdown();
    const int m = o->l + o->r >> 1;
    int ret = 0;
    if (l <= m) ret += query(l, r, o->lson);
    if (m < r) ret += query(l, r, o->rson);
    return ret;
}

} // namespace Segment_Tree
using namespace Segment_Tree;
int main()
{
    int n, q, x;
    scanf("%d%d%d", &n, &q, &x);
    ::x = x;
    vector<long long> low, high;
    low.emplace_back(0);
    high.emplace_back(0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] <= x)
            low.emplace_back(low.back() + a[i]);
        else
            high.emplace_back(high.back() + a[i]);
    }
    shared_ptr<Node> root;
    build(1, n, root);
    for (int i = 0, op, l, r; i < q; i++)
    {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            long long ans = 0;
            int sum = query(l, r, root);
            int total = query(1, r, root);
            ans += high[total] - high[total - sum];
            sum = r - l + 1 - sum;
            total = r - total;
            ans += low[total] - low[total - sum];
            printf("%lld\n", ans);
        }
        else if (op == 2)
        {
            int one = query(l, r, root);
            update(l, r - one, 0, root);
            update(r - one + 1, r, 1, root);
        }
        else if (op == 3)
        {
            int one = query(l, r, root);
            update(l, l + one - 1, 1, root);
            update(l + one, r, 0, root);
        }
        else
            assert(false);
    }
}