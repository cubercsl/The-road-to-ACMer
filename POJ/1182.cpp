// 食物链, POJ1182

/*Sample Input
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 3 * 50010;
int n, k;
int par[maxn], rnk[maxn];
int T[maxn], X[maxn], Y[maxn];

/****************************************/
void init(int n)
{
    for (int i = 0; i < n; i++)
        par[i] = i, rnk[i] = 0;
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite (int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rnk[x] < rnk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}
/****************************************/

void solve()
{
    int ans = 0;
    init (3 * n);
    for (int i = 0; i < k; i++)
    {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1;
        if (x < 0 || y < 0 || x >= n || y >= n)
        {
            ans++;
            continue;
        }
        if (t == 1)
        {
            if (same(x, y + n) || same(x, y + 2 * n))
                ans++;
            else
            {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            if (same(x, y) || same(x, y + 2 * n))
                ans++;
            else
            {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
        scanf("%d%d%d", &T[i], &X[i], &Y[i]);
    solve();
    return 0;
}
