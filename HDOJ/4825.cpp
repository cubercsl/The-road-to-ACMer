// Xor Sum, HDU4825

/*Sample Input
2
3 2
3 4 5
1
5
4 1
4 6 5 6
3
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

const int maxnode = 5e6 + 5;
const int sigma_size = 2;
struct Trie
{
    int ch[maxnode][sigma_size];
    ll val[maxnode];
    int sz;
    Trie() { sz = 1, clr(ch[0], 0); }
    void init() { sz = 1, clr(ch[0], 0); }
    void insert(const ll& x)
    {
        int u = 0;
        for (int i = 32; ~i; i--)
        {
            int c = x >> i & 1;
            if (!ch[u][c])
            {
                clr(ch[sz], 0);
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = x;
    }
    ll find(const ll& x)
    {
        int u = 0;
        for (int i = 32; ~i; i--)
        {
            int c = x >> i & 1;
            if (ch[u][c ^ 1]) c ^= 1;
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
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ans.init();
        int n, m;
        ll num;
        scanf("%d%d", &n, &m);
        while (n--)
        {
            scanf("%lld", &num);
            ans.insert(num);
        }
        printf("Case #%d:\n", ++kase);
        while (m--)
        {
            scanf("%lld", &num);
            printf("%lld\n", ans.find(num));
        }
    }
    return 0;
}
