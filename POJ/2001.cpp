// Shortest Prefixes, POJ2001

/*Sample Input
carbohydrate
cart
carburetor
caramel
caribou
carbonic
cartilage
carbon
carriage
carton
car
carbonate
*/

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
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
    int val[maxnode];
    int sz;
    Trie() { sz = 1, clr(ch[0], 0); }
    inline int idx(char c) { return c - 'a'; }
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
            val[u]++;
        }
    }
    int find(const string& s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (val[u] == 1) return i;
            u = ch[u][c];
        }
        return n;
    }
} ans;
vector<string> v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        v.pb(s);
        ans.insert(s);
    }
    for (int i = 0; i < v.size(); i++)
    {
        s = v[i];
        cout << s << " ";
        int len = ans.find(s);
        for (int i = 0; i < len; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
