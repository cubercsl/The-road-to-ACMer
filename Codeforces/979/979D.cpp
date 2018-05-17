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
    Node* ch[2];
    int val;
    Node() { ch[0] = ch[1] = nullptr, val = INF; }
};

struct Trie
{
    Node* root;
    Trie() { root = new Node(); };
    ~Trie() { clear(root); }
    void clear(Node* o)
    {
        if (o == nullptr) return;
        clear(o->ch[0]);
        clear(o->ch[1]);
        delete o;
    }
    void insert(const int& x)
    {
        Node* o = root;
        o->val = min(o->val, x);
        for (int i = 20; ~i; i--)
        {
            int d = x >> i & 1;
            if (o->ch[d] == nullptr) o->ch[d] = new Node();
            o = o->ch[d];
            o->val = min(o->val, x);
        }
    }
    int query(const int& x, const int& s)
    {
        Node* o = root;
        if (o->val + x > s) return -1;
        int ans = 0;
        for (int i = 20; ~i; i--)
        {
            int d = x >> i & 1;
            if (o->ch[d ^ 1] != nullptr && o->ch[d ^ 1]->val + x <= s) d ^= 1;
            ans |= (d << i);
            o = o->ch[d];
        }
        return ans;
    }
};

const int N = 1 << 17;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int q;
    scanf("%d", &q);
    vector<bool> vis(N);
    vector<Trie> trie(N);
    vector<vector<int> > d(N);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i) d[j].push_back(i);
    while (q--)
    {
        static int t, u, x, k, s;
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &u);
            if (vis[u]) continue;
            vis[u] = true;
            for (auto& x : d[u]) trie[x].insert(u);
        }
        if (t == 2)
        {
            scanf("%d%d%d", &x, &k, &s);
            if (x % k != 0)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", trie[k].query(x, s));
        }
    }
    return 0;
}