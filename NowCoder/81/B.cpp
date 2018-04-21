#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

struct Node
{
    Node* ch[26];
    ll sum, val, add;
    int sz, cnt;
    Node() { sum = val = sz = cnt = add = 0, memset(ch, 0, sizeof(ch)); }
    void pushdown()
    {
        if (add == 0) return;
        for (int i = 0; i < 26; i++)
        {
            if (ch[i] == nullptr) continue;
            ch[i]->sum += add * ch[i]->sz;
            ch[i]->val += add * ch[i]->cnt;
            ch[i]->add += add;
        }
        add = 0;
    }
};
struct Trie
{
    Node* rt;
    Trie() { rt = new Node; }
    ~Trie() { destory(rt); }
    void destory(Node* o)
    {
        if (o == nullptr) return;
        for (int i = 0; i < 26; i++) destory(o->ch[i]);
        delete o;
    }
    void insert(const char* s, int v)
    {
        Node* u = rt;
        for (int i = 0; s[i]; i++)
        {
            u->pushdown();
            u->sum += v, u->sz++;
            int c = s[i] - 'a';
            if (u->ch[c] == nullptr) u->ch[c] = new Node;
            u = u->ch[c];
        }
        u->pushdown();
        u->sum += v, u->sz++;
        u->val += v, u->cnt++;
    }
    void update(const char* s, int v)
    {
        Node* u = rt;
        stack<Node*> stk;
        for (int i = 0; s[i]; i++)
        {
            int c = s[i] - 'a';
            if (u->ch[c] == nullptr) u->ch[c] = new Node;
            stk.push(u);
            u = u->ch[c];
        }
        u->sum += u->sz * v;
        u->val += u->cnt * v;
        u->add += v;
        ll tmp = u->sz * v;
        while (!stk.empty()) stk.top()->sum += tmp, stk.pop();
    }
    ll query(const char* s, bool op = false)
    {
        Node* u = rt;
        for (int i = 0; s[i]; i++)
        {
            u->pushdown();
            int c = s[i] - 'a';
            if (u->ch[c] == nullptr) return 0;
            u = u->ch[c];
        }
        u->pushdown();
        return op ? u->sum : u->val;
    }
};
const int N = 1 << 17;
char buf[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Trie t;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        static int op, x;
        scanf("%d", &op);
        if (op == 1) scanf("%s%d", buf, &x), t.insert(buf, x);
        if (op == 2) scanf("%s%d", buf, &x), t.update(buf, x);
        if (op == 3) scanf("%s", buf), printf("%lld\n", t.query(buf));
        if (op == 4) scanf("%s", buf), printf("%lld\n", t.query(buf, true));
    }
    return 0;
}