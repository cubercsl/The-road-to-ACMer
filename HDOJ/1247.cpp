// Hat’s Words, HDU1247

/*Sample Input
a
ahat
hat
hatword
hziee
word
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
const int sigema_size = 26;
struct Trie
{
    int ch[maxnode][sigema_size];
    bool is_word[maxnode];
    int sz;
    Trie() { sz = 1, clr(ch[0], 0); }
    inline int idx(const char& c) { return c - 'a'; }
    void insert(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                clr(ch[sz], 0);
                is_word[sz] = false;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        is_word[u] = true;
    }
    int find(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c]) return false;
            u = ch[u][c];
        }
        return is_word[u];
    }
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    vector<string> v;
    string s;
    while (cin >> s)
    {
        v.pb(s);
        ans.insert(s);
    }
    for (auto& t : v)
    {
        int n = t.length();
        for (int i = 1; i < n; i++)
        {
            if (ans.find(t.substr(0, i)) && ans.find(t.substr(i)))
            {
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}
