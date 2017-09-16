// Phone List, HDU1671

/*Sample Input
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
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

const int maxnode = 1e6 + 5;
const int sigema_size = 10;
struct Trie
{
    int ch[maxnode][sigema_size];
    bool val[maxnode];
    int sz;
    Trie() { sz = 1, clr(ch[0], 0), val[0] = false; }
    void init() { sz = 1, clr(ch[0], 0), val[0] = false; }
    int idx(char c) { return c - '0'; }
    bool insert(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                clr(ch[sz], 0);
                val[sz] = false;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            if (val[u]) return false;
        }
        val[u] = true;
        for (int i = 0; i < sigema_size; i++)
            if (ch[u][i]) return false;
        return true;
    }
};

Trie ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        string num;
        ans.init();
        int n;
        bool flag = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            // cout << num << endl;
            flag &= ans.insert(num);
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
