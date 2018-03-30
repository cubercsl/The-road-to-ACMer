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

const int N = 505;
const int maxn = 500 * 500 + 5;

string s, t[N];

struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt, tot;
    map<string, int> M;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, tot = 0, M.clear(), rt = newnode(); }
    inline int idx(char c) { return c - 'a'; }
    inline int getid(const string& s) { return M[s] ?: M[s] = ++tot; }
    void insert(const string& s)
    {
        int id = getid(s);
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = id;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int cnt[N];
    void query(const string& s, int n)
    {
        clr(cnt, 0);
        int u = rt;
        int m = s.length();
        for (int i = 0; i < m; i++)
        {
            int c = idx(s[i]);
            u = ch[u][c];
            int tmp = u;
            while (tmp != rt)
            {
                if (~val[tmp]) cnt[val[tmp]]++;
                tmp = f[tmp];
            }
        }
        for (int i = 0; i < n; i++) cout << cnt[getid(t[i])] << endl;
    }
} ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cin >> s;
        ac.init();
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
            ac.insert(t[i]);
        }
        ac.build();
        cout << "Case " << ++kase << ":\n";
        ac.query(s, n);
    }
    return 0;
}
