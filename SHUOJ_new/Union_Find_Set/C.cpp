#include <bits/stdc++.h>
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

const int maxn = 1e5 + 5;
int par[maxn];
int rnk[maxn];
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

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    {
        init(n);
        while (m--)
        {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            if (t == 1)
                unite(x, y);
            else
                printf("%s\n", same(x, y) ? "Yes" : "No");
        }
    }
    return 0;
}
