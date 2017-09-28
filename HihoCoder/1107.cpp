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

const int maxnode = 1 << 20;
const int sigema_size = 30;

struct Trie
{
    int ch[maxnode][sigema_size];
    int val[maxnode];
    int sz;
    inline int idx(char c) { return c - 'a'; }
    Trie()
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
            val[u]++;
        }
    }
    void dfs(int u, int& sum)
    {
        if (val[u] <= 5 && val[u] != 0)
        {
            sum++;
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            if (ch[u][i])
                dfs(ch[u][i], sum);
        }
    }
};

Trie trie;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    string buf;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        trie.insert(buf);
    }
    int sum = 0;
    trie.dfs(0, sum);
    cout << sum << endl;
    return 0;
}
