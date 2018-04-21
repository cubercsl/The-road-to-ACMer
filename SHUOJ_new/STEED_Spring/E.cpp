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

const int N = 10;
int a[N], b[N], id[N];
bool vis[N];
int ch[N][N];

void dfs(int x, int& cnt)
{
    if (vis[x]) return;
    vis[x] = 1, cnt++;
    dfs(id[x], cnt);
}

int magic1(int n)
{
    int ret = 0;
    clr(vis, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        int cnt = 0;
        dfs(i, cnt);
        ret += cnt - 1;
    }
    return ret;
}

int magic2(int x, int y)
{
    int ret = 0;
    if (x < y) swap(x, y);
    while (x / 2 >= y)
    {
        ret += (x & 1) + 1;
        x >>= 1;
    }
    ret += x - y;
    return ret;
}

int gao(int n)
{
    int ret = magic1(n);
    for (int i = 0; i < n; i++) ret += ch[id[i]][i];
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        iota(id, id + n, 0);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++) scanf("%d", b + i);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) ch[i][j] = magic2(a[i], b[j]);
        int ans = INF;
        do
            ans = min(ans, gao(n));
        while (next_permutation(id, id + n));
        printf("%d\n", ans);
    }
    return 0;
}