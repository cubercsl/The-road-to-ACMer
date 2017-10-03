// Hyper Prefix Sets, UVa11488

/*Sample Input
4
4
0000
0001
10101
010
2
01010010101010101010
11010010101010101010
3
010101010101000010001010
010101010101000010001000
010101010101000010001010
5
01010101010100001010010010100101
01010101010100001010011010101010
00001010101010110101
0001010101011010101
00010101010101001
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

const int maxnode = 1e7 + 5;
struct Trie
{
    int ch[maxnode][2];
    int val[maxnode];
    int sz;
    int newnode()
    {
        clr(ch[sz], 0), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, newnode(); }
    void insert(const char s[])
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            bool c = s[i] == '0';
            if (!ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
            val[u]++;
        }
    }
    void dfs(int u, int dep, int& sum)
    {
        sum = max(dep * val[u], sum);
        for (int c = 0; c < 2; c++)
            if (ch[u][c]) dfs(ch[u][c], dep + 1, sum);
    }
};

Trie trie;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    char s[205];
    scanf("%d", &T);
    while (T--)
    {
        trie.init();
        int n;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%s", s);
            trie.insert(s);
        }
        int sum = 0;
        trie.dfs(0, 0, sum);
        printf("%d\n", sum);
    }
    return 0;
}
