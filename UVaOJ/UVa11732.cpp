// "strcmp()" Anyone?, UVa11732

/*Sample Input
2
a
b
4
cat
hat
mat
sir
0
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

const int maxnode = 4e6 + 5;
struct Trie
{
    int head[maxnode];
    int next[maxnode];
    char ch[maxnode];
    int tot[maxnode];
    int sz;
    ll ans;
    void init() { sz = 1, tot[0] = head[0] = next[0] = 0; }
    void insert(const char* s)
    {
        int u = 0, v, n = strlen(s);
        tot[0]++;
        for (int i = 0; i <= n; i++)
        {
            bool found = false;
            for (v = head[u]; v; v = next[v])
            {
                if (ch[v] == s[i])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                v = sz++;
                tot[v] = 0;
                ch[v] = s[i];
                next[v] = head[u];
                head[u] = v;
                head[v] = 0;
            }
            u = v;
            tot[u]++;
        }
    }
    void dfs(int dep, int u)
    {
        if (!head[u])
        {
            ans += tot[u] * (tot[u] - 1) * dep;
            return;
        }
        int sum = 0;
        for (int v = head[u]; v; v = next[v])
            sum += tot[v] * (tot[u] - tot[v]);
        ans += sum / 2 * (2 * dep + 1);
        for (int v = head[u]; v; v = next[v])
            dfs(dep + 1, v);
    }
    ll query()
    {
        ans = 0;
        dfs(0, 0);
        return ans;
    }
} trie;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, kase = 0;
    char s[1005];
    while (~scanf("%d", &n) && n)
    {
        trie.init();
        while (n--)
        {
            scanf("%s", s);
            trie.insert(s);
        }
        printf("Case %d: %lld\n",++kase,trie.query());
    }
    return 0;
}
