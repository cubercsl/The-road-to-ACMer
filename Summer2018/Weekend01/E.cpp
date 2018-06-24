#include <cstdio>
using namespace std;

typedef long long ll;

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    go();
    return 0;
}

/****************************************************************************************************/

struct Node
{
    Node *lson, *rson;
    int addv;
    ll sumv;
};

void pushup(Node* o, int m) { o->sumv = o->lson->sumv + o->rson->sumv + 1LL * o->addv * m; }
const int N = 100002;
Node mem[N * 30];
int tot = 0;

void build(int l, int r, Node*& o)
{
    o = &mem[++tot];
    o->addv = 0;
    if (l == r)
    {
        scanf("%lld", &o->sumv);
        return;
    }
    int m = l + r >> 1;
    build(l, m, o->lson);
    build(m + 1, r, o->rson);
    pushup(o, r - l + 1);
}

void update(int L, int R, int v, int l, int r, Node*& o, Node* p)
{
    o = &mem[++tot];
    *o = *p;
    if (L <= l && r <= R)
    {
        o->addv += v;
        o->sumv += 1LL * v * (r - l + 1);
        return;
    }
    int m = l + r >> 1;
    if (L <= m) update(L, R, v, l, m, o->lson, p->lson);
    if (m < R) update(L, R, v, m + 1, r, o->rson, p->rson);
    pushup(o, r - l + 1);
}

ll query(int L, int R, int l, int r, int addv, Node* o)
{
    if (L <= l && r <= R) return o->sumv + 1LL * addv * (r - l + 1);
    addv += o->addv; // pushdown
    int m = l + r >> 1;
    ll sum = 0;
    if (L <= m) sum += query(L, R, l, m, addv, o->lson);
    if (m < R) sum += query(L, R, m + 1, r, addv, o->rson);
    return sum;
}

Node* root[N];

void go()
{
    int n, m;
    bool flag = 0;
    while (~scanf("%d%d", &n, &m))
    {
        if (flag) puts("");
        flag = 1;
        char op[5];
        int l, r, d, t;
        int T = 0;
        build(1, n, root[0]);
        while (m--)
        {
            scanf("%s", op);
            if (op[0] == 'C')
            {
                scanf("%d%d%d", &l, &r, &d);
                ++T;
                update(l, r, d, 1, n, root[T], root[T - 1]);
            }
            else if (op[0] == 'Q')
            {
                scanf("%d%d", &l, &r);
                printf("%lld\n", query(l, r, 1, n, 0, root[T]));
            }
            else if (op[0] == 'H')
            {
                scanf("%d%d%d", &l, &r, &t);
                printf("%lld\n", query(l, r, 1, n, 0, root[t]));
            }
            else
            {
                scanf("%d", &T);
                tot = root[T + 1] - root[0];
            }
        }
        tot = 0;
    }
}