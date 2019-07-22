#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

template <typename T, typename U>
class ModInt
{

public:
    static const U MOD = 1e9 + 7;

private:
    T data;

public:
    ModInt() : data() {}
    template <typename V>
    ModInt(const V& data_) : data(data_ % MOD) {}

    template <typename V>
    explicit operator V() const noexcept { return data; }

    ModInt& operator+=(const ModInt& b) noexcept
    {
        data = (U(data) + b.data) % MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& b) noexcept
    {
        data = (U(data) + MOD - b.data) % MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& b) noexcept
    {
        data = (U(data) * b.data) % MOD;
        return *this;
    }

    friend ModInt operator+(const ModInt& a, const ModInt& b) noexcept { return (U(a.data) + b.data) % MOD; }
    friend ModInt operator-(const ModInt& a, const ModInt& b) noexcept { return (U(a.data) + MOD - b.data) % MOD; }
    friend ModInt operator*(const ModInt& a, const ModInt& b) noexcept { return (U(a.data) * b.data) % MOD; }

    friend bool operator==(const ModInt& a, const ModInt& b) noexcept { return a.data == b.data; }
    friend bool operator!=(const ModInt& a, const ModInt& b) noexcept { return a.data != b.data; }
    friend bool operator<(const ModInt& a, const ModInt& b) noexcept { return a.data < b.data; }
    friend bool operator>(const ModInt& a, const ModInt& b) noexcept { return a.data > b.data; }
    friend bool operator<=(const ModInt& a, const ModInt& b) noexcept { return a.data <= b.data; }
    friend bool operator>=(const ModInt& a, const ModInt& b) noexcept { return a.data >= b.data; }
};

using ModInt32 = ModInt<std::uint32_t, std::uint64_t>;

namespace SegmentTree
{
struct Node
{
    ModInt32 sum, len;
    ModInt32 tagl, tagr, taglen;
    Node *lson, *rson;

    int l, r;

    int getlength() const { return r - l + 1; }

    int getmid() const { return l + r >> 1; }

    void init(int l, int r)
    {
        this->l = l, this->r = r;
        sum = 0, len = 1, tagl = tagr = 0, taglen = 1;
        lson = rson = NULL;
    }

    void pushup()
    {
        sum = lson->sum + rson->sum;
        len = lson->len + rson->len;
    }

    void pushdown()
    {
        if (taglen == 1) return;

        lson->tagl += tagl * lson->taglen;
        rson->tagl += tagl * rson->taglen;

        (lson->tagr *= taglen) += tagr;
        (rson->tagr *= taglen) += tagr;

        (lson->sum *= taglen) += (tagr * lson->getlength() + tagl * lson->len * taglen);
        (rson->sum *= taglen) += (tagr * rson->getlength() + tagl * rson->len * taglen);

        lson->len *= (taglen * taglen);
        rson->len *= (taglen * taglen);

        lson->taglen *= taglen;
        rson->taglen *= taglen;

        tagl = tagr = 0, taglen = 1;
    }

} pool[N << 2];
int sz;

void init() { sz = 0; }

Node* newNode(int l, int r)
{
    pool[sz].init(l, r);
    return &pool[sz++];
}

void build(int l, int r, Node*& o)
{
    o = newNode(l, r);
    if (l == r) return;
    const int m = o->getmid();
    build(l, m, o->lson);
    build(m + 1, r, o->rson);
    o->pushup();
}

void update(int L, int R, ModInt32 d, Node* o)
{
    if (L <= o->l && o->r <= R)
    {
        (o->sum *= 10) += (d * o->getlength() + o->len * 10 * d);
        o->len *= 100;
        o->tagl += o->taglen * d;
        (o->tagr *= 10) += d;
        o->taglen *= 10;
        return;
    }
    o->pushdown();
    const int m = o->getmid();
    if (L <= m) update(L, R, d, o->lson);
    if (m < R) update(L, R, d, o->rson);
    o->pushup();
}

ModInt32 query(int L, int R, Node* o)
{
    if (L <= o->l && o->r <= R) return o->sum;
    o->pushdown();
    const int m = o->getmid();
    ModInt32 ans = 0;
    if (L <= m) ans += query(L, R, o->lson);
    if (m < R) ans += query(L, R, o->rson);
    return ans;
}

} // namespace SegmentTree

using namespace SegmentTree;

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        Node* rt;
        init();
        build(1, n, rt);
        printf("Case %d:\n", ++kase);
        for (int i = 0, l, r, d; i < m; i++)
        {
            static char op[10];
            scanf("%s%d%d", op, &l, &r);
            if (op[0] == 'w')
            {
                scanf("%d", &d);
                update(l, r, d, rt);
            }
            else
                printf("%d\n", static_cast<int>(query(l, r, rt)));
        }
    }
}