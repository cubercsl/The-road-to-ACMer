#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e7;
struct Node
{
    int sz, tag;
    Node* ch[2];
    Node() : sz(0), tag(0) { memset(ch, 0, sizeof(ch)); }
    void maintain()
    {
        sz = 0;
        if (ch[0] != nullptr) sz += ch[0]->sz;
        if (ch[1] != nullptr) sz += ch[1]->sz;
    }
    void pushdown()
    {
        if (tag == 0) return;
        if (tag & 1)
        {
            swap(ch[0], ch[1]);
            if (ch[0] != nullptr) ch[0]->tag++;
        }
        if (tag > 1)
        {
            if (ch[0] != nullptr) ch[0]->tag += (tag >> 1);
            if (ch[1] != nullptr) ch[1]->tag += (tag >> 1);
        }
        tag = 0;
    }
} mem[maxn];

Node* newNode()
{
    static int tot = 0;
    assert(tot + 1 < maxn);
    return &mem[tot++];
};

struct Trie
{
    void insert(Node*& o, int x, int dep = 30)
    {
        if (o == nullptr) o = newNode();
        if (dep == 0)
        {
            o->sz++;
            return;
        }
        o->pushdown();
        insert(o->ch[x & 1], x >> 1, dep - 1);
        o->maintain();
    }
    Node* merge(Node* o, Node* k, int dep = 30)
    {
        if (o == nullptr) return k;
        if (k == nullptr) return o;
        if (o == nullptr && k == nullptr) return nullptr;
        if (dep == 0)
        {
            o->sz += k->sz;
            return o;
        }
        o->pushdown(), k->pushdown();
        o->ch[0] = merge(o->ch[0], k->ch[0], dep - 1);
        o->ch[1] = merge(o->ch[1], k->ch[1], dep - 1);
        o->maintain();
        return o;
    }
    int query(Node* o, int x, int dep)
    {
        if (o == nullptr) return 0;
        if (dep == 0) return o->sz;
        o->pushdown();
        return query(o->ch[x & 1], x >> 1, dep - 1);
    }
};

struct DSU
{
    vector<int> fa;
    DSU() {}
    DSU(int n) { fa.resize(n), iota(fa.begin(), fa.end(), 0); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) { fa[find(y)] = find(x); }
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    DSU d(n);
    Trie t;
    vector<Node*> rt(n);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        t.insert(rt[i], x);
    }
    while (m--)
    {
        static int op, u, v, k, x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &u, &v);
            --u, --v;
            u = d.find(u), v = d.find(v);
            if (u != v)
            {
                rt[u] = t.merge(rt[u], rt[v]);
                d.merge(u, v);
            }
        }
        else if (op == 2)
        {
            scanf("%d", &u);
            --u;
            rt[d.find(u)]->tag++;
        }
        else
        {
            scanf("%d%d%d", &u, &k, &x);
            --u;
            printf("%d\n", t.query(rt[d.find(u)], x, k));
        }
    }
    return 0;
}