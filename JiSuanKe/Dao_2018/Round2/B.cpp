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

const int N = 1 << 20;
struct Trie
{
    int sz, rt;
    int ch[N][26];
    ll cnt[N], val[N];
    int newNode()
    {
        clr(ch[sz], -1), cnt[sz] = 0, val[sz] = 0;
        return sz++;
    }
    void init()
    {
        sz = 0;
        rt = newNode();
    }
    void insert(const string& s, int v)
    {
        int u = rt;
        for (auto& t : s)
        {
            int c = t - 'a';
            cnt[u] += v;
            if (!~ch[u][c]) ch[u][c] = newNode();
            u = ch[u][c];
        }
        cnt[u] += v;
        val[u] += v;
    }
    void remove(const string& s)
    {
        int u = rt;
        stack<int> ss;
        for (auto& t : s)
        {
            ss.push(u);
            int c = t - 'a';
            if (!~ch[u][c])
            {
                cout << "Empty" << endl;
                return;
            }
            u = ch[u][c];
        }
        ll t = val[u];
        if (t == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        val[u] = 0;
        cnt[u] -= t;
        while (!ss.empty())
        {
            cnt[ss.top()] -= t;
            ss.pop();
        }
    }
    ll query(const string& s)
    {
        int u = rt;
        for (auto& t : s)
        {
            int c = t - 'a';
            if (!~ch[u][c]) return 0;
            u = ch[u][c];
        }
        return cnt[u];
    }
} gao;

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
        int n;
        cin >> n;
        gao.init();
        while (n--)
        {
            string op, s;
            int x;
            cin >> op >> s;
            reverse(s.begin(), s.end());
            if (op == "insert")
            {
                cin >> x;
                gao.insert(s, x);
            }
            if (op == "delete") gao.remove(s);
            if (op == "query") cout << gao.query(s) << endl;
        }
    }
    return 0;
}