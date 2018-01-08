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
const int mod = 10000;
const double eps = 1e-6;

const int N = 10005;

vector<int> G[N];
int fa[N];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) G[i].clear(), fa[i] = i;
}

int dis[N], sum[N];

void bfs(int n)
{
    clr(dis, -1);
    clr(sum, 0);
    queue<int> q;
    dis[1] = 0;
    sum[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                sum[v] = sum[u];
                q.push(v);
            }
            else if (dis[v] == dis[u] + 1)
                (sum[v] += sum[u]) %= mod;
        }
    }
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

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
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        while (m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
            G[v].pb(u);
            u = find(u), v = find(v);
            if (u == v) continue;
            fa[v] = u;
        }
        if (find(1) != find(n))
        {
            printf("-1\n");
            continue;
        }
        bfs(n);
        printf("%d\n", sum[n]);
    }
    return 0;
}
