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

const int maxnode = 1e6 + 5;
struct Trie
{
    int ch[maxnode][2];
    int val[maxnode];
    int sz;
    Trie() { sz = 1, clr(ch[0], -1); }
    void init() { sz = 1, clr(ch[0], -1); }
    void insert(const int& n)
    {
        int u = 0;
        for (int i = 17; ~i; i--)
        {
            int c = ((n >> i) & 1);
            if (ch[u][c] == -1)
            {
                clr(ch[sz], -1);
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            val[u]++;
        }
    }
    ll query(const int& n, const int& m)
    {
        int u = 0;
        ll ret = 0;
        for (int i = 17; ~i && ~u; i--)
        {
            int tmp = ((m >> i) & 1);
            int c = ((n >> i) & 1);
            if (tmp == 0)
            {
                if (~ch[u][c ^ 1]) ret += val[ch[u][c ^ 1]];
                u = ch[u][c];
            }
            else
                u = ch[u][c ^ 1];
        }
        return ret;
    }
};

Trie trie;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    int a[100005];
    while (~scanf("%d%d", &n, &m))
    {
        trie.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            trie.insert(a[i]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += trie.query(a[i], m);
        printf("%lld\n", ans / 2);
    }
    return 0;
}
