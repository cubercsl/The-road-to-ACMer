#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int p[17];
const int base = 1021;
 
const int N = 16;
struct Node
{
    int a[N];
    Node() { memset(a, 0, sizeof(a)); }
    Node(int x) { *this = Node(), a[x] = 1; }
    int& operator[](const int& x) { return a[x]; }
    int operator()() const
    {
        int x = 0;
        for (int i = 0; i < N; i++) (x += 1LL * a[i] * p[i] % mod) %= mod;
        return x;
    }
    friend Node operator+(Node l, Node r)
    {
        Node ret;
        for (int i = 0; i < N; i++) ret[i] = (l[i] + r[i]) % mod;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                int k = (i + j) % 15;
                if (k == 0 && (i + j)) k = 15;
                (ret[k] += 1LL * l[i] * r[j] % mod) %= mod;
            }
        return ret;
    }
};
 
const int maxn = 1 << 17;
char buf[maxn];
inline int idx(char a) { return isdigit(a) ? a - '0' : a - 'A' + 10; }
 
namespace SegmentTree
{
Node s[maxn << 2];
 
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
 
void build(int l, int r, int o)
{
    if (l == r)
    {
        s[o] = Node(idx(buf[l]));
        return;
    }
    int m = l + r >> 1;
    build(Lson), build(Rson);
    s[o] = s[lson] + s[rson];
}
 
void update(const int& p, const char& v, int l, int r, int o)
{
    if (l == r)
    {
        s[o] = Node(idx(v));
        return;
    }
    int m = l + r >> 1;
    if (p <= m)
        update(p, v, Lson);
    else
        update(p, v, Rson);
    s[o] = s[lson] + s[rson];
}
 
Node query(const int& L, const int& R, int l, int r, int o)
{
    if (L <= l && r <= R) return s[o];
    int m = l + r >> 1;
    Node ret;
    if (L <= m) ret = ret + query(L, R, Lson);
    if (m < R) ret = ret + query(L, R, Rson);
    return ret;
}
 
}; // namespace SegmentTree
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    p[0] = 1;
    for (int i = 1; i < 17; i++) p[i] = 1LL * p[i - 1] * base % mod;
    int n, q;
    scanf("%d%d%s", &n, &q, buf + 1);
    SegmentTree::build(1, n, 1);
    static char ch[5];
    while (q--)
    {
        static int op, l, r;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%s", &l, ch);
            SegmentTree::update(l, ch[0], 1, n, 1);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", SegmentTree::query(l, r, 1, n, 1)());
        }
    }
}