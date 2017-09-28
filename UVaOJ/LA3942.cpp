// Remember the Word, LA3942

/*Sample Input
abcd
4
a
b
cd
ab
*/

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
const int mod = 20071027;
const double eps = 1e-6;

const int maxn = 3e5 + 5;
int dp[maxn];

const int maxnode = 1 << 20;
const int sigema_size = 26;

struct Trie
{
    int ch[maxnode][sigema_size];
    bool val[maxnode];
    int sz;
    inline int idx(char c) { return c - 'a'; }
    void init()
    {
        sz = 1;
        clr(ch[0], 0);
    }
    void insert(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                clr(ch[sz], 0);
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = 1;
    }
    int query(const string& s, int st)
    {
        int ret = 0;
        int u = 0, n = s.length();
        for (int i = st; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
                return ret;
            u = ch[u][c];
            if (val[u])
                ret = (ret + dp[i + 1]) % mod;
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
    fastin string s;
    int kase = 0;
    while (cin >> s)
    {
        trie.init();
        clr(dp, 0);
        int n;
        cin >> n;
        string buf;
        while (n--)
        {
            cin >> buf;
            trie.insert(buf);
        }
        int len = s.length();
        dp[len] = 1;
        for (int i = len - 1; ~i; i--)
            dp[i] = trie.query(s, i);
        cout << "Case " << ++kase << ": " << dp[0] << endl;
    }
    return 0;
}
