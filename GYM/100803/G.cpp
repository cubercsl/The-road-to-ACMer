#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct Node
{
    Node *lson, *rson;
    int l, r;
    int minv, tag;
    Node(int l, int r) : minv(-INF), l(l), r(r), tag(0){};
    void pushup()
    {
        minv = min(lson->minv, rson->minv);
    }
    void pushdown()
    {
        if (tag == 0) return;
        lson->tag += tag;
        rson->tag += tag;
        lson->minv += tag;
        rson->minv += tag;
        tag = 0;
    }
};

const int N = 1 << 19;
int sum[N];

void build(int l, int r, Node*& o)
{
    o = new Node(l, r);
    if (l == r)
    {
        o->minv = sum[l];
        return;
    }
    const int m = l + r >> 1;
    build(l, m, o->lson);
    build(m + 1, r, o->rson);
    o->pushup();
}

void update(int l, int r, int v, Node* const& o)
{
    if (l <= o->l && o->r <= r)
    {
        o->minv += v;
        o->tag += v;
        return;
    }
    const int m = o->l + o->r >> 1;
    o->pushdown();
    if (l <= m) update(l, r, v, o->lson);
    if (m < r) update(l, r, v, o->rson);
    o->pushup();
}

int query(int l, int r, Node* const& o)
{
    if (l <= o->l && o->r <= r) return o->minv;
    const int m = o->l + o->r >> 1;
    o->pushdown();
    int ans = INF;
    if (l <= m) ans = min(ans, query(l, r, o->lson));
    if (m < r) ans = min(ans, query(l, r, o->rson));
    return ans;
}
char str[N];
int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    set<int> left, right;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            sum[i + 1]++;
            left.insert(i + 1);
        }
        else
        {
            sum[i + 1]--;
            right.insert(i + 1);
        }
    }
    Node *rt = nullptr;
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    build(1, n, rt);
    while (m--)
    {
        scanf("%d", &x);
        if (str[x - 1] == '(')
        {
            int p = *right.begin();
            if (p < x)
            {
                printf("%d\n", p);
                str[x - 1] = ')';
                str[p - 1] = '(';
                left.erase(x);
                right.erase(p);
                left.insert(p);
                right.insert(x);
                update(p, n, 2, rt);
                update(x, n, -2,rt);
            }
            else
                printf("%d\n", x);
        }
        else{
            int l = 1, r = x - 1;
            int p = -1;
            while (l <= r)
            {
                int m = l + r >> 1;
                if (query(m, x - 1, rt) >= 2)
                {
                    p = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if(p == -1){
                printf("%d\n", x);
            }
            else{
                printf("%d\n", p);
                str[x - 1] = '(';
                str[p - 1] = ')';
                left.erase(p);
                right.erase(x);
                left.insert(x);
                right.insert(p);
                update(x, n, 2, rt);
                update(p, n, -2, rt);
            }
        }
    }
}
