// Keywords Search, HDU2222

/*Sample Input
1
5
she
he
say
shr
her
yasherhs
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

const int maxn = 500050;
struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u]++;
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
                {
                    f[ch[u][c]] = ch[f[u]][c];
                    q.push(ch[u][c]);
                }
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    int query(const string& s)
    {
        int u = rt, n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            u = ch[u][c];
            int tmp = u;
            while (tmp != rt)
            {
                res += val[tmp];
                val[tmp] = 0;
                tmp = f[tmp];
            }
        }
        return res;
    }
};

Trie ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int T;
    cin >> T;
    while (T--)
    {
        ac.init();
        int n;
        string buf;
        cin >> n;
        while (n--)
        {
            cin >> buf;
            ac.insert(buf);
        }
        ac.build();
        cin >> buf;
        cout << ac.query(buf) << endl;
    }
    return 0;
}
