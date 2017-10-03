// Dictionary Size, UVa1519

/*Sample Input
3
abc
def
abef
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
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxnode = 4e5 + 5;
struct Trie
{
    int ch[maxnode][26];
    int cnt[26];
    int sz;
    int newnode()
    {
        clr(ch[sz], 0);
        return sz++;
    }
    void init() { sz = 0, clr(cnt, 0), newnode(); }
    inline int idx(char c) { return c - 'a'; }
    void insert(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                ch[u][c] = newnode();
                if (i) cnt[c]++;
            }
            u = ch[u][c];
        }
    }
};

Trie pre, suf;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    int vis[26];
    while (cin >> n)
    {
        pre.init();
        suf.init();
        clr(vis, 0);
        string s;
        while (n--)
        {
            cin >> s;
            if (s.length() == 1)
                vis[s[0] - 'a'] = 1;
            pre.insert(s);
            reverse(s.begin(), s.end());
            suf.insert(s);
        }
        ll ans = (ll)(pre.sz - 1) * (suf.sz - 1);
        for (int i = 0; i < 26; i++)
            ans -= (ll)pre.cnt[i] * suf.cnt[i] - vis[i];
        cout << ans << endl;
    }
    return 0;
}
