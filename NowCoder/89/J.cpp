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

const int N = 1 << 17;
vector<int> G[N];
int in[N], out[N], fa[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}

inline bool judge(int& st, int n)
{
    st = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += find(i) == i;
        if (in[i] > 1 || out[i] > 1) return false;
        if (in[i] == 0) st = i;
    }
    if (st == -1) return false;
    return cnt == 1;
}

vector<int> ans;
void dfs(int u)
{
    for (auto& v : G[u]) dfs(v);
    ans.push_back(u);
}

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
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) vector<int>().swap(G[i]), in[i] = out[i] = 0, fa[i] = i;
        while (m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            unite(u, v);
            out[u]++, in[v]++;
        }
        printf("Case #%d:\n", ++kase);
        vector<int>().swap(ans);
        int st = 0;
        if (judge(st, n))
        {
            dfs(st);
            for (int i = n - 1; ~i; i--) printf("%d%c", ans[i], " \n"[i == 0]);
        }
        else
            puts("NO");
    }
    return 0;
}