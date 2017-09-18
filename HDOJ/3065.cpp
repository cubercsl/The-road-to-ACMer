// 病毒侵袭持续中, HDU3065

/*Sample Input
3
AA
BB
CC
ooxxCC%dAAAoen....END
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

string str[1005];

struct Trie
{
    int next[500010][128], fail[500010], end[500010];
    int root, L;
    int newnode()
    {
        clr(next[L], -1);
        end[L++] = -1;
        return L - 1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(const string& buf, int id)
    {
        int len = buf.length();
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][buf[i]] == -1)
                next[now][buf[i]] = newnode();
            now = next[now][buf[i]];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 128; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 128; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int vis[1010];
    void query(const string& buf, int n)
    {
        clr(vis, 0);
        bool flag = 0;
        int len = buf.length();
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while (temp != root)
            {
                if (end[temp] != -1)
                    vis[end[temp]]++;
                temp = fail[temp];
            }
        }
        for (int i = 0; i < n; i++)
            if (vis[i]) cout << str[i] << ": " << vis[i] << endl;
    }
};

Trie ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    string buf;
    while (cin >> n)
    {
        ac.init();
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
            ac.insert(str[i], i);
        }
        ac.build();
        cin >> buf;
        ac.query(buf, n);
    }
    return 0;
}
