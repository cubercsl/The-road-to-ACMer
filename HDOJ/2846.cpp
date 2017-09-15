// Repository, HDU2846

/*Sample Input
20
ad
ae
af
ag
ah
ai
aj
ak
al
ads
add
ade
adf
adg
adh
adi
adj
adk
adl
aes
5
b
a
d
ad
s
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
const int sigma_size = 26;
struct Trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int id[maxnode];
    int sz;
    Trie() { sz = 1, clr(ch[0], 0); }
    inline int idx(const char& c) { return c - 'a'; }
    void insert(const char* s, const int& num)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c])
            {
                clr(ch[sz], 0);
                val[sz] = 0;
                id[sz] = -1;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            if (id[u] != num) val[u]++;
            id[u] = num;
        }
    }
    int find(const char* s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c]) return 0;
            u = ch[u][c];
        }
        return val[u];
    }
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    char s[25];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < strlen(s); j++)
            ans.insert(s + j, i);
    }
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        printf("%d\n", ans.find(s));
    }
    return 0;
}
