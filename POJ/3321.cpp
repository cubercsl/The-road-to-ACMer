// Apple Tree, POJ3321

/*Sample Input
3
1 2
1 3
3
Q 1
C 2
Q 1
*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int bit[maxn], a[maxn];
int L[maxn], R[maxn];
int n, dfs_clock;
vector<vector <int> > G(maxn);

inline int lowbit(int x)
{
    return x & (-x);
}

void update (int x, int val)
{
    while (x <= n)
    {
        bit[x] += val;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

void init()
{
    clr(bit, 0);
    dfs_clock = 0;
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void dfs(int u)
{
    L[u] = ++dfs_clock;
    for (int i = 0; i < G[u].size(); i++)
        dfs(G[u][i]);
    R[u] = dfs_clock;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
        }
        dfs(1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = 1;
            update(L[i], 1);
        }
        int q, x;
        char c[2];
        scanf("%d", &q);
        while (q--)
        {
            scanf("%s%d", c, &x);
            if (c[0] == 'Q')
                printf("%d\n", query(R[x]) - query(L[x] - 1));
            else
            {
                update(L[x], a[x] ? -1 : 1);
                a[x] ^= 1;
            }
        }
    }
    return 0;
}
